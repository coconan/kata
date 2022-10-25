#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int main(void){

	int k;
	int i,j;

	int sum = 0;
	int max = 0;
	int start,rs;
	int end,flag;
	vector<int> list;
	while(scanf("%d",&k)!=EOF){
		sum = 0;
		max = -1;
		start = 0;
		rs = 0;
		list.clear();
		end = 0;
		flag = 0;
		for(i=0;i<k;i++){
			scanf("%d",&j);
			if(j>=0) flag = 1;
			sum+=j;
			list.push_back(j);
			if(sum>max){ max = sum; end = i; rs = start;}
			if(sum<=0) {sum = 0; start = i+1;}
		}
		if(flag==1){
		printf("%d %d %d\n",max,list[rs],list[end]);
		}else 	printf("0 %d %d\n",list[0],list[k-1]);
	}

	return 0;
}