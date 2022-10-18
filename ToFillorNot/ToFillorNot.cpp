//****************************************
//*程 序：ToFillorNot.cpp                *
//*作 者：ytm                            *
//*时 间：2013-2-26                      *
//*功 能：编程题库/浙江大学-机试/2012 第 *
//*       三题                           *
//****************************************

#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	double price;
	double distance;
}GasStation;

bool compare(GasStation a, GasStation b) {
	return a.distance < b.distance;
}

double maxDistance(GasStation gasStation[], int n, double capacity, double distance, double Davg) {
	double range = capacity * Davg;
	double maxDist = 0.0;
	if(gasStation[0].distance != 0) return maxDist;
	for(int i = 0; i < n - 1; i++) {
		if(gasStation[i+1].distance - gasStation[i].distance <= range) {
			maxDist = gasStation[i+1].distance;
		} else {
			break;
		}
	}
	return maxDist + range;
}

double minCost(GasStation gasStation[], int n, double capacity, double distance, double Davg) {
	double cost = 0.0;
	double remain = 0.0;
	double range = capacity * Davg;
	int i = 0, j = 1;
	while (j < n)
	{
		while(gasStation[j].price > gasStation[i].price && j < n && 
			  gasStation[j].distance - gasStation[i].distance <= range) j++;
		if(j == n) {
			if(distance - gasStation[i].distance <= range) {
				return cost += ((distance - gasStation[i].distance) / Davg - remain) * gasStation[i].price;
			} else {
				cost += (capacity - remain) * gasStation[i].price;
				remain = capacity - (gasStation[n - 1].distance - gasStation[i].distance) / Davg;
				i = j - 1;
			}
		} else if(gasStation[j].distance - gasStation[i].distance > range) {
			cost += (capacity - remain) * gasStation[i].price;
			remain = capacity - (gasStation[j - 1].distance - gasStation[i].distance) / Davg;
			i = j - 1;
		} else {
			cost += ((gasStation[j].distance - gasStation[i].distance) / Davg - remain) * gasStation[i].price;
			remain = 0.0;
			i = j;
			j++;
		}
	}
	return cost += ((distance - gasStation[i].distance) / Davg - remain) * gasStation[i].price;
}

int main() {
	GasStation gasStation[500];
	double capacity, distance, Davg;
	int n;
	scanf("%lf%lf%lf%d", &capacity, &distance, &Davg, &n);
	int i = 0;
	while(i < n) {
		scanf("%lf%lf", &gasStation[i].price, &gasStation[i].distance);
		i++;
	}
	sort(gasStation, gasStation + n, compare);
	double maxDist = maxDistance(gasStation, n, capacity, distance, Davg);
	if(maxDist > distance) {
		printf("%.2lf\n", minCost(gasStation, n, capacity, distance, Davg));
	} else {
		printf("The maximum travel distance = %.2lf\n", maxDist);
	}
	return 0;
}

