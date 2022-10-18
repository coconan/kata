#include<iostream>  
#include<stdio.h> 
#include<stack> 
#include<vector>
using namespace std;  

int main()  
{
	vector<int>v;
	stack<int>s;
	v.clear();
	int n,b;
	cin>>n;
	cin>>b;
	if(n==0)
	{
		printf("Yes\n0");
		return 0;
	}
	while(n!=0)
	{
		s.push(n%b);
		n=n/b;
	}
	while(!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	int i;
	for(i=0;i<v.size();i++)
	{
		if(v[i]!=v[v.size()-i-1])
			break;
	}
	if(i==v.size())
		printf("Yes\n");
	else
		printf("No\n");
	for(i=0;i<v.size();i++)
	{
		if(i!=v.size()-1)
			printf("%d ",v[i]);
		else
			printf("%d",v[i]);
	}
	return 0;
} 