#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "gclFile.h"
#include "gclTimer.h"

using namespace std;
#define width 8192
#define height 8192

#pragma comment (lib,"OpenCL.lib")

//等待事件完成
int waitForEventAndRelease(cl_event *event)
	{
	cl_int status = CL_SUCCESS;
	cl_int eventStatus = CL_QUEUED;
	while(eventStatus != CL_COMPLETE)
		{
		status = clGetEventInfo(
			*event, 
			CL_EVENT_COMMAND_EXECUTION_STATUS, 
			sizeof(cl_int),
			&eventStatus,
			NULL);
		}

	status = clReleaseEvent(*event);

	return 0;
	}

int main(int argc, char* argv[])
	{
	//在host内存中创建三个缓冲区
	float *buf1 = 0;
	float *buf2 = 0;
	float *buf = 0;

	buf1 =(float *)malloc(width * height * sizeof(float));
	buf2 =(float *)malloc(width * height * sizeof(float));
	buf =(float *)malloc(width * height * sizeof(float));

	//用一些随机值初始化buf1和buf2的内容
	int i;
	srand( (unsigned)time( NULL ) ); 
	for(i = 0; i < width*height; i++)
		buf1[i] = rand()%65535;

	srand( (unsigned)time( NULL ) +1000);
	for(i = 0; i < width*height; i++)
		buf2[i] = rand()%65535;

	gclTimer clTimer;
	clTimer.Reset();
	clTimer.Start();
	//cpu计算buf1,buf2的和
	for(i = 0; i < width*height; i++)
		buf[i] = buf1[i] * buf2[i];
	clTimer.Stop();
	printf("cpu costs time:%.6f ms \n ", clTimer.GetElapsedTime()*1000 );

	//告诉driver dump il和isa文件
	_putenv("GPU_DUMP_DEVICE_KERNEL=3");

	cl_uint status;
	cl_platform_id platform;

	//创建平台对象
	//status = clGetPlatformIDs( 1, &platform, NULL );
	cl_uint numPlatforms;
	std::string platformVendor; 
	status = clGetPlatformIDs(0, NULL, &numPlatforms);
	if(status != CL_SUCCESS)
		{
		return 0;
		}
	if (0 < numPlatforms) 
		{
		cl_platform_id* platforms = new cl_platform_id[numPlatforms];
		status = clGetPlatformIDs(numPlatforms, platforms, NULL);

		char platformName[100];
		for (unsigned i = 0; i < numPlatforms; ++i) 
			{
			status = clGetPlatformInfo(platforms[i],
				CL_PLATFORM_VENDOR,
				sizeof(platformName),
				platformName,
				NULL);

			platform = platforms[i];
			platformVendor.assign(platformName);

			if (!strcmp(platformName, "Advanced Micro Devices, Inc.")) 
				{
				break;
				}
			}

		std::cout << "Platform found : " << platformName << "\n";
		delete[] platforms;
		}
	cl_device_id device;

	//创建GPU设备
	clGetDeviceIDs( platform, CL_DEVICE_TYPE_GPU,
		1,
		&device,
		NULL);
	//创建context
	cl_context context = clCreateContext( NULL,
		1,
		&device,
		NULL, NULL, NULL);
	//创建命令队列
	cl_command_queue queue = clCreateCommandQueue( context,
		device,
		CL_QUEUE_PROFILING_ENABLE, NULL );
	//创建三个OpenCL内存对象，并把buf1的内容通过隐式拷贝的方式
	//拷贝到clbuf1,buf2的内容通过显示拷贝的方式拷贝到clbuf2
	cl_mem clbuf1 = clCreateBuffer(context,
		CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
		width*height*sizeof(cl_float),buf1,
		NULL );

	cl_mem clbuf2 = clCreateBuffer(context,
		CL_MEM_READ_ONLY ,
		width*height*sizeof(cl_float),NULL,
		NULL );

	cl_event writeEvt;
	status = clEnqueueWriteBuffer(queue, clbuf2, 1,
		0, width*height*sizeof(cl_float), buf2, 0, 0, &writeEvt);
	status = clFlush(queue);
	//等待数据传输完成再继续往下执行
	waitForEventAndRelease(&writeEvt);
	//clWaitForEvents(1, &writeEvt);

	cl_mem buffer = clCreateBuffer( context,
		CL_MEM_WRITE_ONLY,
		width*height * sizeof(cl_float),
		NULL, NULL );

	//kernel文件为add.cl

	gclFile kernelFile;
	if(!kernelFile.open("add.cl"))
		{
		printf("Failed to load kernel file \n");
		exit(0);
		}
	const char * source = kernelFile.source().c_str();
	size_t sourceSize[] = {strlen(source)};
	//创建程序对象
	cl_program program = clCreateProgramWithSource(
		context, 
		1, 
		&source,
		sourceSize,
		NULL);
	//编译程序对象
	status = clBuildProgram( program, 1, &device, NULL, NULL, NULL );
	if(status != 0)
		{
		printf("clBuild failed:%d\n", status);
		char tbuf[0x10000];
		clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0x10000, tbuf, NULL);
		printf("\n%s\n", tbuf);
		return -1;
		}

	//创建Kernel对象
	cl_kernel kernel = clCreateKernel( program, "vecadd", NULL );
	//设置Kernel参数
	cl_int clnum = width*height;
	clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*) &clbuf1);
	clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*) &clbuf2);
	clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*) &buffer);


	//执行kernel,Range用2维，work itmes size为width*height,
	cl_event ev;
	size_t globalThreads[] = {width, height};
	size_t localx, localy;
	if(width/8 > 4)
		localx = 16;
	else if(width < 8)
		localx = width;
	else localx = 8;

	if(height/8 > 4)
		localy = 16;
	else if (height < 8)
		localy = height;
	else localy = 8;

	size_t localThreads[] = {localx, localy}; // localx*localy应该是64的倍数 
	printf("global_work_size =(%d,%d), local_work_size=(%d, %d)\n",width,height,localx,localy);

	clTimer.Reset();
	clTimer.Start();
	clEnqueueNDRangeKernel( queue,
		kernel,
		2,
		NULL,
		globalThreads,
		localThreads, 0, NULL, &ev);
	//没有设置local group size时候，系统将会自动设置为 (256,1)
	status = clFlush( queue );
	waitForEventAndRelease(&ev);
	 //clWaitForEvents(1, &ev);

	clTimer.Stop();

	printf("kernal total time:%.6f ms \n ", clTimer.GetElapsedTime()*1000 );

	//数据拷回host内存
	cl_float *ptr;
	clTimer.Reset();
	clTimer.Start();
	cl_event mapevt;
	ptr = (cl_float *) clEnqueueMapBuffer( queue,
		buffer,
		CL_TRUE,
		CL_MAP_READ,
		0,
		width*height * sizeof(cl_float),
		0, NULL, &mapevt, NULL );
	status = clFlush( queue );
	waitForEventAndRelease(&mapevt);
	//clWaitForEvents(1, &mapevt);
	clTimer.Stop();
	printf("copy from device to host:%.6f ms \n ", clTimer.GetElapsedTime()*1000 );

	//结果验证，和cpu计算的结果比较
	if(!memcmp(buf, ptr, width*height))
		printf("Verify passed\n");
	else printf("verify failed");

	if(buf)
		free(buf);
	if(buf1)
		free(buf1);
	if(buf2)
		free(buf2);

	//删除OpenCL资源对象
	clReleaseMemObject(clbuf1); 
	clReleaseMemObject(clbuf2);
	clReleaseMemObject(buffer);
	clReleaseProgram(program);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);
	return 0;
	}

