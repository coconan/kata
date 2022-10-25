#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
	char sid[12];
	char sname[12];
	char sex;
	int grade;
}node;

vector<node> student;
int n;

bool cmp(node a,node b){
	return a.grade<b.grade;
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		student.clear();
		for(i=0;i<n;i++){
			node tnode;
			scanf("%s %c %s %d",tnode.sname,&tnode.sex,tnode.sid,&tnode.grade);
			student.push_back(tnode);
		}
		int pf,pm;
		pf = pm = -1;
		sort(student.begin(),student.end(),cmp);
		for(i=student.size()-1;i>=0;i--){
			if(student[i].sex=='F'){
				pf=i;
				break;
			}
		}

		for(i=0;i<=student.size()-1;i++){
			if(student[i].sex=='M'){
				pm=i;
				break;
			}
		}
		if(pf==-1){
			printf("Absent\n");
		}else
			printf("%s %s\n",student[pf].sname,student[pf].sid);
		if(pm==-1){
			printf("Absent\n");
		}else
			printf("%s %s\n",student[pm].sname,student[pm].sid);
		if(pf==-1||pm==-1){
			printf("NA\n");
		}else
			printf("%d\n",student[pf].grade-student[pm].grade);

	}
	return 0;
}