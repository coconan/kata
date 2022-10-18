#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(void)
{
	int N,M;
	scanf("%d",&N);
	int i;
	int *dist=(int*)malloc(sizeof(int)*N);
	int sum=0;
	for(i=0;i<N;i++)
	{
		scanf("%d",dist+i);
		sum+=dist[i];
		dist[i]=sum;
	}
	int halfsum=sum/2;


	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		int d1,d2;
		scanf("%d %d",&d1,&d2);
		if(d1>d2)
		{
			int temp=d2;
			d2=d1;
			d1=temp;
		}
		int d;
		if(d1==1)
			d=dist[d2-2];
		else
			d=dist[d2-2]-dist[d1-2];
		if(d>halfsum)
			d=sum-d;
		if(i!=0)
			printf("\n");
		printf("%d",d);
	}
	return 0;
}