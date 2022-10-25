#include<stdio.h>
#include<string.h>
using namespace std;

double a[1002];
double b[1002];


int main(void){
	int n,i,temp;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		scanf("%lf",&a[temp]);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		scanf("%lf",&b[temp]);
	}
	int count = 0;
	for(i=0;i<1002;i++){
		a[i]+=b[i];
		if(a[i]!=0) count++;
	}
	printf("%d",count);
	for(i=1001;i>=0;i--)
		if(a[i]!=0){
			count--;
			printf(count==0?" %d %.1f\n":" %d %.1f",i,a[i]);
			
		}

	return 0;
}
