#include <stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define N 1000100
long m,n,a[N],b[N],c[N*2];
int main()
{
    long int i,j,k,t,mid;
    scanf("%d",&m);
    for(i=0;i<m;i++)
		scanf("%ld",a+i);
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%ld",b+i);
		merge(a,a+m,b,b+n,c);
	  if((m+n)%2==1)
	  	printf("%ld\n",c[(m+n)/2]);
	  	else
		printf("%ld\n",c[(m+n)/2-1]);
    return 0;
}
