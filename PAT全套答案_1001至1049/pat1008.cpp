#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	//freopen("D://test.txt","r",stdin);
	int n,total=0;
	cin>>n;
	int rq[10000];
	rq[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>rq[i];
		if(rq[i]>rq[i-1])
			total=total+(rq[i]-rq[i-1])*6;
		else if(rq[i]<rq[i-1])
			total=total+(rq[i-1]-rq[i])*4;
	}
	total=total+n*5;
	cout<<total<<endl;
	return 0;
}
