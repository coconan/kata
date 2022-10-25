#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<set>
#include<queue>
using namespace std;

bool isPrime(int x)
{
	if(x<2)
		return false;
	if(x==2||x==3)
		return true;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	//freopen("D://test.txt","r",stdin);
	int n,d;
	while(cin>>n)
	{
		if(n<0)
			break;
		else
		{
			cin>>d;
			if(isPrime(n))
			{
				queue<int>q;
				while(n!=0)
				{
					q.push(n%d);
					n=n/d;
				}
				int reverse=0;
				while(!q.empty())
				{
					reverse=reverse*d;
					reverse=reverse+q.front();
					q.pop();
				}
				if(isPrime(reverse))
				{
					cout<<"Yes"<<endl;
				}
				else
				{
					cout<<"No"<<endl;
				}
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
