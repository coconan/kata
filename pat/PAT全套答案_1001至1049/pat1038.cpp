#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct{
	char num[10];
}node;

vector<node> record;
string s,s1;

bool cmp(node a,node b){
	s="";
	s1="";
	s = a.num;
	s+=b.num;
	s1 = b.num;
	s1+=a.num;
	
	if(strcmp(s.c_str(),s1.c_str())>0) return false;
}

int main(void){
	int n,i;
	scanf("%d",&n);
	record.clear();
	long long fint;
	for(i=0;i<n;i++){
		node tn;
		scanf("%s",tn.num);
		fint = atoi(tn.num);
		if(fint!=0){
			record.push_back(tn);
		}
	}
	if(record.size()==0){
		printf("0");
	}
	else{
		sort(record.begin(),record.end(),cmp);
		fint = atoi(record[0].num);
		printf("%lld",fint);
		
		for(i=1;i<record.size();i++){
			printf("%s",record[i].num);
		}
	}
	putchar('\n');
	return 0;
}