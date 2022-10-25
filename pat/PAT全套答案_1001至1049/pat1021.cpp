#include<iostream>  
#include<stdio.h> 
#include<stack> 
#include<vector>
#include<stack>
#include<queue>
#include<string.h>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;  

int dist[10010];
vector<int>adj_list[10010];
int P[10010];


struct Number
{
	int point;
	int dis;
};

vector<Number>num;

//return the  max distance
int bfs(int start , int V)
{
	memset(dist,-1,sizeof(dist));
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	int dmax = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		int d = dist[now];
		for(int i = 0; i < adj_list[now].size(); i++)
		{
			//not visit before
			if(dist[ adj_list[now][i] ] == -1)
			{
				dist[ adj_list[now][i] ] = d +1;
				q.push(adj_list[now][i]);
			}
		}
		if(d > dmax)
		{
			dmax = d;
		}
	}
	return dmax;
}

bool cmp1(Number a,Number b)
{
	if(a.dis==b.dis)
		return a.point<b.point;
	return a.dis>b.dis;
}

bool cmp2(Number a,Number b)
{
	return a.point<b.point;
}


int Union_Find(int id)
{
	if(P[id]==-1)
		return id;
	else
		return Union_Find(P[id]);
}

void Union_Union(int a,int b)
{
	int id1=Union_Find(a);
	int id2=Union_Find(b);
	if(id1!=id2)
		P[id1]=id2;
}

int main()  
{
	//freopen("D://test.txt","r" , stdin);
	int i;
	int a,b,n;
	scanf("%d",&n);
	memset(P,-1,sizeof(P));
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		Union_Union(a,b);
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	int count=0;
	for(i=1;i<=n;i++)
	{
		if(P[i]==-1)
			count++;
	}
	if(count!=1)
		printf("Error: %d components",count);
	else
	{
		int temp;
		num.clear();
		Number buf;
		for(i=1;i<=n;i++)
		{
			buf.point=i;
			temp=bfs(i,n);
			buf.dis=temp;
			num.push_back(buf);
		}
		sort(num.begin(),num.end(),cmp1);
		int pos;
		for(i=0;i<n;i++)
		{
			if(i!=n-1)
			{
				if(num[i].dis!=num[i+1].dis)
				{
					pos=i;
					break;
				}
			}
			else
			{
				pos=i;
			}
		}
		//sort(num.begin(),num.begin()+pos,cmp2);
		for(i=0;i<=pos;i++)
		{
			if(i!=pos)
				printf("%d\n",num[i].point);
			else
				printf("%d",num[i].point);
		}
	}
	return 0;
} 
