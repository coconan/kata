#include<stdio.h>
#include<string.h>
using namespace std;

int n;
int ary[100002];
int ary1[100002];

int main(void){
	int i,temp;
	while(scanf("%d",&n)!=EOF){
		memset(ary,0,sizeof(ary));
		for(i=0;i<n;i++){
			scanf("%d",&temp);
			ary1[i] = temp;
			ary[temp]++;
		}
		for(i=0;i<n;i++){
			if(ary[ary1[i]]==1){
				printf("%d\n",ary1[i]);
				break;
			}
		}
		if(i==n){
				printf("None\n");
		}
	}
	return 0;
}