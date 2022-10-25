#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
	double price;
	int place;
}node;

vector<node> station;

bool cmp(node a,node b){
	return a.place<b.place;
}

int main(void){
	int c,d,ad,n;
	int i,j,k;
	while(scanf("%d%d%d%d",&c,&d,&ad,&n)!=EOF){
		station.clear();
		for(i=0;i<n;i++){
			node tnode;
			scanf("%lf %d",&tnode.price,&tnode.place);
			station.push_back(tnode);
		}
		sort(station.begin(),station.end(),cmp);
		double cost = 0;
		double maxd = 0;
		double cd = 0;
		double cgas = 0;
		if(station[0].place!=0){
		
			printf("The maximum travel distance = 0.00\n");
			continue;
		}
		int temd;
		int visited = 0;
		for(i=0;i<n;i++){
			cd = station[i].place;
			temd = cd + c*ad;
			int flag = 0;
			if(i==n-1){
				if((d-station[n-1].place)*1.0/ad-cgas>0){
					cost+= ((d-station[n-1].place)*1.0/ad-cgas)*station[n-1].price;
					if(c*ad+station[n-1].place<d){
						printf("The maximum travel distance = %.2f\n",c*ad+station[n-1].place*1.0);
						visited = 1;
					}
				}
				break;
			}
			for(j=i+1;j<n&&station[j].place<=temd;j++){
				if(station[j].price<=station[i].price){
					if(cgas*ad+cd<station[j].place){
						cost += ((station[j].place - station[i].place)*1.0/ad-cgas)*station[i].price;
						cgas = (station[j].place - station[i].place)*1.0/ad;
					}
					flag = 1;
					break;
				}
			}
			if(flag==0){
				if(temd>d){
					cost+= ((d-cd)*1.0/ad - cgas)*station[i].price;
					cgas = (d-cd)*1.0/ad;
				}else {
					cost+= (c-cgas)*station[i].price;
					cgas = c;
				}
			}
			cgas = cgas - (station[i+1].place-station[i].place)*1.0/ad;
			
		}
		if(visited==0){
			printf("%.2f\n",cost);
		}
	}
	return 0;
}