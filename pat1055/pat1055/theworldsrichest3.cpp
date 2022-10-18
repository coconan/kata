//#include <stdio.h>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <string.h>
//#include <iostream>
//#include <memory.h>
//
//using namespace std;
//
//struct Person {
//	int age, wealth;
//	char name[10];
//};
//
//Person people[100005], peoplePruned[100005];
//int ageCount[201];
//
//bool cmp(const Person a, const Person b) {
//	if (a.wealth == b.wealth) {
//		if (a.age == b.age) {
//			return strcmp(a.name, b.name) < 0;
//		}
//		return a.age < b.age;
//	}
//	return a.wealth > b.wealth;
//}
//
//int main() {
//	//freopen("data.in", "r", stdin);
//	int n, k, prunedN = 0;
//	Person p;
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].wealth);
//	}
//
//	sort(people, people+n, cmp);
//	for (int i = 0; i < n; i++) {
//		if (ageCount[people[i].age] < 100) {
//			peoplePruned[prunedN++] = people[i];
//			ageCount[people[i].age]++;
//		}
//	}
//
//	for (int i = 0; i < k; i++) {
//		int m, Amin, Amax, counter = 0;
//		scanf("%d %d %d", &m, &Amin, &Amax);
//		printf("Case #%d:\n", i+1);
//		for (int j = 0; j < prunedN && counter < m; j++) {
//			if (Amin <= peoplePruned[j].age && peoplePruned[j].age <= Amax) {
//				printf("%s %d %d\n", peoplePruned[j].name, peoplePruned[j].age, peoplePruned[j].wealth);
//				counter++;
//			}
//		}
//		if (counter == 0) {
//			printf("None\n");
//		}
//	}
//	return 0;
//}