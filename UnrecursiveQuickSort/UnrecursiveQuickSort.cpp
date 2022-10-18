//************************************************
//程序：UnrecursiveQuickSort.cpp
//时间：2012-12-16
//功能：快速排序的非递归实现
//感悟：细节是魔鬼啊！看起来简单，做起来难。多动手，多实践。
//************************************************

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 256

int stack[MAX_SIZE];

int main ()
{
	int n;
	cout<<"size = ";
	cin>>n;
	
	int array[128];
	
	for ( int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		cout<< array[i] << " ";
	}
	cout<< endl;

	int top = -1;
	stack[++top] = n - 1;
	stack[++top] = 0;

	while (top != -1)
	{
		int s = stack[top--];
		int t = stack[top--];
		int low = s;
		int high = t;
		
		int pivot = (s + t + (s + t) / 2) / 3;
		int pivotkey = array[pivot];
        while (low < high)
		{
			while ((array[low] <= pivotkey) && (low < pivot)) 
				low++;
			array[pivot] = array[low];
			pivot = low;

			while ((array[high] >= pivotkey) && (pivot < high))
				high--;
			array[pivot] = array[high];
			pivot = high;
		}
		array[pivot] = pivotkey;
		
		if (pivot < t)
		{
			stack[++top] = t;
			stack[++top] = pivot + 1;
		}

		if (pivot > s)
		{
			stack[++top] = pivot -1;
			stack[++top] = s;
		}
	}

	for (i = 0; i < n; i++)
	{
		cout<< array[i] << " ";
	}
	return 1;
}
