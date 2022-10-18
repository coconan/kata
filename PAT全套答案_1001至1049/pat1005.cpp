#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<set>
using namespace std;

int main()
{
	string numE[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int i;
	map<char,int>m;
	for(i=0;i<=9;i++)
	{
		m['0'+i]=i;
	}
	string str;
	cin>>str;
	int sum=0;
	for(i=0;i<str.length();i++)
	{
		sum+=m[str[i]];
	}
	char c[10000];
	string strSum;
	sprintf(c,"%d",sum);
	strSum=c;
	for(i=0;i<strSum.length();i++)
	{
		if(i!=strSum.length()-1)
		{
			int temp=strSum[i]-48;
			cout<<numE[temp]<<" ";
		}
		else
		{
			int temp=strSum[i]-48;
			cout<<numE[temp]<<endl;
		}
	}
	return 0;
}
