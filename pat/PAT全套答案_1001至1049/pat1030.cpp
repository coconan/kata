#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
	int cost;
	int dist;
}node;
const int INF = 1<<30;
int dist[502];
int path[502];
int cost[502];
int used[502];
node mat[502][502];

vector<int> rpath;
int n,m,s,e;

void dij(){
	int j,i;
	dist[s] = 0;

	while(true){
		int p,min=INF;
		for(i=0;i<n;i++)
			if(!used[i]&&dist[i]<min) min = dist[p=i];
		if(p==e||min==INF)
			return;
		used[p] = 1;
		for(j=0;j<n;j++){
			if(used[j]==0){
				int tdist = dist[p] + mat[p][j].dist;
				if(tdist<dist[j]){
					path[j] = p;
					dist[j] = tdist;
					cost[j] = cost[p]+mat[p][j].cost;
				}else if(tdist==dist[j]){
					int tcost = cost[p]+mat[p][j].cost;
					if(cost[j]>tcost){
						path[j] = p;
						dist[j] = tdist;
						cost[j] = tcost;
					}
				}
			}
		}
	}
}

int main(void){
	int i,j,k;
	while(scanf("%d%d%d%d",&n,&m,&s,&e)!=EOF){
		rpath.clear();
		for(i=0;i<n;i++){
			dist[i]=INF;
			path[i]=-1;
			cost[i]=0;
			used[i]=0;
			for(j=0;j<n;j++){
				mat[i][j].dist = mat[j][i].dist = INF;
				mat[i][j].cost = mat[j][i].cost = INF;
			}
		}
		for(i=0;i<m;i++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&d,&c);
			mat[a][b].cost = mat[b][a].cost = c;
			mat[a][b].dist = mat[b][a].dist = d;
		}
	
		dij();
	
		int temp = e;
		rpath.push_back(temp);
		while(true){
			temp = path[temp];
			if(temp!=-1)
				rpath.push_back(temp);
			else
				break;
		}
		for(i=rpath.size()-1;i>=0;i--)
			printf("%d ",rpath[i]);
		printf("%d %d\n",dist[e],cost[e]);
	}
	return 0;
}