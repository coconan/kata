//****************************************
//*程 序：Gang.cpp                       *
//*作 者：ytm                            *
//*时 间：2013-2-26                      *
//*功 能：编程题库/浙江大学-机试/2010 第 *
//*       三题                           *
//****************************************

#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	int no;
	int orderValue[4];
	int order[4];
}Country;

bool compare0(Country a, Country b) {
	return a.orderValue[0] >= b.orderValue[0];
}

bool compare1(Country a, Country b) {
	return a.orderValue[1] >= b.orderValue[1];
}

bool compare2(Country a, Country b) {
	return a.orderValue[2] >= b.orderValue[2];
}
bool compare3(Country a, Country b) {
	return a.orderValue[3] >= b.orderValue[3];
}

bool compare4(Country a, Country b) {
	return a.no < b.no;
}

int main() {
	int n, m, i, j, high;
	int gold, medal, population;
	Country country[300];
	int countryForRanking[300];
	while(scanf("%d%d", &n, &m) != EOF) {
		for(i = 0; i < n; i++) {
			country[i].no = i;
			scanf("%d%d%d",&gold, &medal, &population);
			country[i].no = i;
			country[i].orderValue[0] = gold;
			country[i].orderValue[1] = medal;
			country[i].orderValue[2] = (float) gold / population;
			country[i].orderValue[3] = (float) medal / population;
		}
		for(i = 0; i < m; i++) {
			scanf("%d", &countryForRanking[i]);
		}
		sort(country, country + n, compare0);
		for(i = 0; i < n; i++) {
			if(i > 0 && country[i].orderValue[0] == country[i-1].orderValue[0]) {
				country[i].order[0] = country[i-1].order[0];
			} else {
				country[i].order[0] = i + 1;
			}
		}
		sort(country, country + n, compare1);
		for(i = 0; i < n; i++) {
			if(i > 0 && country[i].orderValue[1] == country[i-1].orderValue[1]) {
				country[i].order[1] = country[i-1].order[1];
			} else {
				country[i].order[1] = i + 1;
			}
		}
		sort(country, country + n, compare2);
		for(i = 0; i < n; i++) {
			if(i > 0 && country[i].orderValue[2] == country[i-1].orderValue[2]) {
				country[i].order[2] = country[i-1].order[2];
			} else {
				country[i].order[2] = i + 1;
			}
		}
		sort(country, country + n, compare3);
		for(i = 0; i < n; i++) {
			if(i > 0 && country[i].orderValue[3] == country[i-1].orderValue[3]) {
				country[i].order[3] = country[i-1].order[3];
			} else {
				country[i].order[3] = i + 1;
			}
		}
		sort(country, country + n, compare4);
		for(i = 0; i < m; i++) {
			high = 0;
			for(j = 0; j < 4; j++) {
				if(country[countryForRanking[i]].order[j] < country[countryForRanking[i]].order[high]) {
					high = j;
				}
			}
			printf("%d : %d\n", country[countryForRanking[i]].order[high], high + 1);
		}
		printf("\n");
	}
	return 0;
}