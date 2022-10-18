#include "iostream"
#include "algorithm"
#include "functional"
#include "memory.h"
using namespace std;
#define  N 10010
#define T 101
#define INF 3600*50
#define max(a,b) a<b?b:a
bool played[N];
int table[T],nserve[T];
int v[N];//vip ids
bool usedt[T],isvipt[T];
int totaltable,n;

struct Players
{
	int playtime;
	int come;
	bool vip;
}p[N];

bool cmp1(Players A,Players B)
{
	return A.come<B.come;
}

inline void print(int t)
{
	int h = t/3600;
	int  m = (t/60)%60;
	t = t%60;
	printf("%02d:%02d:%02d ",h,m,t);
}

inline void Allocate(int t_id,int p_id)
{
	if(table[t_id]>=21*3600)
		return;
	played[p_id] = true;
	print(p[p_id].come);
	print(table[t_id]);
	int wait = max(0,table[t_id]-p[p_id].come);
	printf("%d\n",(wait+30)/60);
	table[t_id] += p[p_id].playtime;
	nserve[t_id]++;
}

int main()
{
	int i,j,n_vip=0,tt,n_viptable,tmp; 
	char st[15];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s%d%d",&st,&p[i].playtime,&p[i].vip);
		if(p[i].playtime>2*60)
			p[i].playtime=  120;
		p[i].playtime*=60;
		int h = atoi(strtok(st,":"));
		int m = atoi(strtok(NULL,":"));
		int s = atoi(strtok(NULL,":"));
		tt=s+60*(m+60*h);
		p[i].come = tt;
	}
	scanf("%d%d",&totaltable,&n_viptable);
	memset(isvipt,false,sizeof(isvipt));
	memset(nserve,0,sizeof(nserve));
	for (i=0;i<n_viptable;i++)
	{
		scanf("%d",&tmp);tmp--;
		isvipt[tmp] = true;
	}
	for(i=0;i<totaltable;i++)
		table[i] = 8*3600;
	memset(usedt,false,sizeof(usedt));

	sort(p,p+n,cmp1);
	for(i=0;i<n;i++)
	{
		if(p[i].vip)
		{
			v[n_vip++] = i;
		}
	}
	memset(played,false,sizeof(played));
	int c_vip =0;
	for(i=0;i<n;)
	{
		if(played[i]){
			i++;continue;}
		int time = p[i].come;
		int fast = INF,table_idx,hasvipt = -1, minidx_vac = -1;
		bool full = true;
		for(j=0;j<totaltable;j++)
		{
			if(table[j]<=time) // not full
			{
				full = false;
				if(minidx_vac==-1) //first vacate table
					minidx_vac = j;
				if(isvipt[j])
				{
					hasvipt = j; //first vip table
					break;
				}
			}
			if(full && table[j]<fast) // if full
			{
				fast = table[j];
				table_idx = j; //first table to be idle
			}
		}
		if(full)
		{
			if(c_vip<n_vip&& isvipt[table_idx] && p[v[c_vip]].come<fast) //has vip and  vip table
			{
				Allocate(table_idx,v[c_vip++]);
				continue;
			}
			else // no vip or <vip has no vip table>
			{
				Allocate(table_idx,i);
				if(p[i++].vip)
					c_vip++;
			}
		}
		else // not full
		{
			if(p[i].vip) // has vip
			{
				c_vip++;
				if(hasvipt!=-1) // has vip table
				{
					table[hasvipt] = p[i].come;
					Allocate(hasvipt,i++);
					continue;
				}
			}
			// no vip or <vip has no vip table>
			table[minidx_vac] = p[i].come;
			Allocate(minidx_vac,i++);
		}
	}
	for(i=0;i<totaltable-1;i++)
		printf("%d ",nserve[i]);
	printf("%d\n",nserve[i]);
	//system("pause");
	return 0;
}