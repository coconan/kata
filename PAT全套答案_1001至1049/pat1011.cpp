#include<map>
#include<string>
#include<iostream>
using namespace std;

void out(int f)
{
	if(f==0)
		cout<<"W ";
	else if(f==1)
		cout<<"T ";
	else
		cout<<"L ";
}

int main()
{
	
	double num[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>num[i][j];
	}
	int flag;
	double result=1;
	for(i=0;i<3;i++)
	{
		double max=-1;
		flag=0;
		for(j=0;j<3;j++)
		{
			if(max<num[i][j])
			{
				flag=j;
				max=num[i][j];
			}
		}
		result=result*num[i][flag];
		out(flag);
	}
	result=(result*0.65-1)*2;
	printf("%.2lf\n",result);
	return 0;
}