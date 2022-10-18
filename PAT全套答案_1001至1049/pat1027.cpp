#include<stdio.h>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int main(void){
	int a,b,c;
	stack<int > p;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		string s="#";
		if(a==0) s+="00";
		else if(a<=12) s+="0";
		while(a!=0){
			p.push(a%13);
			a = a/13;
		}

		while(p.empty()!=true){
			if(p.top()==10) s+='A';
			else if(p.top()==11) s+='B';
			else if(p.top()==12) s+='C';
			else {
				char temp[10];
				sprintf(temp,"%d",p.top());
				string ts = temp;
				s+= ts;
			}
			p.pop();
		}
		if(b==0) s+="00";
		else if(b<=12) s+="0";
		while(b!=0){
			p.push(b%13);
			b = b/13;
		}
		while(p.empty()!=true){
			if(p.top()==10) s+='A';
			else if(p.top()==11) s+='B';
			else if(p.top()==12) s+='C';
			else {
				char temp[10];
				sprintf(temp,"%d",p.top());
				string ts = temp;
				s+= ts;
			}
			p.pop();
		}
		if(c==0) s+="00";
		else if(c<=12) s+="0";
		while(c!=0){
			p.push(c%13);
			c = c/13;
		}
	while(p.empty()!=true){
			if(p.top()==10) s+='A';
			else if(p.top()==11) s+='B';
			else if(p.top()==12) s+='C';
			else {
				char temp[10];
				sprintf(temp,"%d",p.top());
				string ts = temp;
				s+= ts;
			}
			p.pop();
		}
		printf("%s\n",s.c_str());
	}
	return 0;
}