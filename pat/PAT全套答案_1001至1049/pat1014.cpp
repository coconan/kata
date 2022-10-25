#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int custime[1002];
int cusend[1002];
typedef struct {
	vector<int> list;
}node;

node team[22];

int main(void){
	int n,m,k,q;
	int i,j,l;
	while(scanf("%d%d%d%d",&n,&m,&k,&q)!=EOF){
		for(i=0;i<22;i++)
			team[i].list.clear();
		memset(cusend,0,sizeof(cusend));
		for(i=1;i<=k;i++){
			scanf("%d",&custime[i]);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				team[i].list.push_back(n*(j-1)+1+i-1);
			
				if(j==1){
					cusend[n*(j-1)+1+i-1] = custime[n*(j-1)+1+i-1];
				}
				else
					cusend[n*(j-1)+1+i-1] = custime[n*(j-1)+1+i-1] + cusend[n*(j-2)+1+i-1];

			}
		}

	
		for(i=n*m+1;i<=k;i++){
			int min = 1<<30;
			int p;
			for(j=1;j<=n;j++){
				if(cusend[team[j].list[0]]<min){
					min = cusend[team[j].list[0]];
					p = j;
				}
			}
			team[p].list.erase(team[p].list.begin());
			team[p].list.push_back(i);
			cusend[i] = cusend[team[p].list[team[p].list.size()-2]] + custime[i];
		
		}
	
		for(i=1;i<=q;i++){
			int temp;
			scanf("%d",&temp);
			int hour = 0;
			int min = 0;
			hour = 8+(cusend[temp]-custime[temp])/60;
			min = (cusend[temp]-custime[temp])%60;
			if(hour>17||(hour==17&&min>=0)){
				printf("Sorry\n");
			}else{
			hour =8+ cusend[temp]/60;
			min = cusend[temp]%60;
			printf("%02d:%02d\n",hour,min);
			}
		}

		
	}
}