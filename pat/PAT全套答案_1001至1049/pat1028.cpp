#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct{
	char sid[8];
	char sname[10];
	int grade;
}node;

vector<node> student;

bool cmp1(node a,node b){
	if(strcmp(a.sid,b.sid)<0) return true;
	return false;
}

bool cmp2(node a,node b){
	if(strcmp(a.sname,b.sname)==0){
			if(strcmp(a.sid,b.sid)<0) return true;
			return false;
	}
	if(strcmp(a.sname,b.sname)<0) return true;
	return false;
}

bool cmp3(node a,node b){
	if(a.grade==b.grade){
			if(strcmp(a.sid,b.sid)<0) return true;
			return false;
	}
	return a.grade<b.grade;
}

int main(void){
	int n,c;
	int i;

	while(scanf("%d%d",&n,&c)!=EOF){
		student.clear();
		for(int i=0;i<n;i++){
			node tn;
			scanf("%s %s %d",tn.sid,tn.sname,&tn.grade);
			student.push_back(tn);
		}
		if(c==1){
			sort(student.begin(),student.end(),cmp1);
		}else if(c==2){
			sort(student.begin(),student.end(),cmp2);
		}else {
			sort(student.begin(),student.end(),cmp3);
		}
		for(i=0;i<student.size();i++){
			printf("%s %s %d\n",student[i].sid,student[i].sname,student[i].grade);
		}
	}

	return 0;
}