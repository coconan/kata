#include<stdio.h>
#include<stdlib.h>
using namespace std;

int compare(const void *data1,const void *data2)
{
	int *ptr1=(int*)data1;
	int *ptr2=(int*)data2;
	return ptr1[0]>=ptr2[0];
}
int search(int key,int *v, int n)
{
	int left=0,right=n;
	while(right>left)
	{
		int mid=(right+left)/2;
		int key1=v[mid];
		if(key1<key)
			left=mid+1;
		else if(key1>key)
			right=mid;
		else
			return key1;
	}
	return v[left];
}
int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);
	int *v=(int*)malloc(sizeof(int)*N);
	int i;
	for(i=0;i<N;i++)
		scanf("%d",v+i);
	qsort(v,N,sizeof(int),compare);

	for(i=0;i<N-1;i++)
	{
		int t=M-v[i];
		int t1=search(t,v+i+1,N-i-1);
		if(t1==t)
		{
			printf("%d %d",v[i],t1);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}