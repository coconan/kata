#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

bool connect[1010][1010],f[1010],connectTemp[1010][1010],fTemp[1010];
int n,m,k;

void dfs(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(connectTemp[i][j]&&fTemp[j]==false)
		{
			fTemp[j]=true;
			dfs(j);
		}
	}
	return;
}

int main()
{
	freopen("D://test.txt","r",stdin);
	memset(connect,0,sizeof(connect));
	memset(f,0,sizeof(f));
	cin>>n>>m>>k;
	int i,j,h;
	for(i=0;i<m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		connect[t1][t2]=connect[t2][t1]=true;
	}
	for(i=0;i<k;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(h=1;h<=n;h++)
			{
				connectTemp[j][h]=connect[j][h];
			}
		}
		for(j=1;j<=n;j++)
		{
			fTemp[j]=f[j];
		}
		int t;
		cin>>t;
		for(j=1;j<=n;j++)
		{
			connectTemp[t][j]=connectTemp[j][t]=0;
		}
		int count=0;
		for(j=1;j<=n;j++)
		{
			if(!fTemp[j])
			{
				count++;
				fTemp[j]=true;
				dfs(j);
			}
		}
		cout<<count-2<<endl;
	}
	return 0;
}
