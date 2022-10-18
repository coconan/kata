//#include <stdio.h>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <string.h>
//#include <iostream>
//
//using namespace std;
//
//struct Person {
//	int age, wealth;
//	char name[10];
//};
//
//Person people[100005];
//int ageAccu[201];
//int ageCount[201];
//
//
//bool cmp(const Person a, const Person b) {
//	if (a.wealth == b.wealth) {
//		if (a.age == b.age) {
//			return strcmp(a.name, b.name) > 0;
//		}
//		return a.age < b.age;
//	}
//	return a.wealth > b.wealth;
//}
//
//bool cmp2(const Person a, const Person b) {
//	return a.age < b.age;
//}
//
//struct mycomparison
//{
//  bool operator() (const Person& a, const Person& b)
//  {
//    if (a.wealth == b.wealth) {
//		if (a.age == b.age) {
//			return strcmp(a.name, b.name) > 0;
//		}
//		return a.age > b.age;
//	}
//	return a.wealth < b.wealth;
//  }
//};

//int main() {
//	//freopen("data.in", "r", stdin);
//	int n, k;
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].wealth);
//		ageCount[people[i].age]++;
//	}
//	sort(people, people+n, cmp2);
//	for (int i = 1; i < 201; i++) {
//		ageAccu[i] = ageCount[i] + ageAccu[i-1];
//	}
//	for (int i = 0; i < k; i++) {
//		int m, Amin, Amax, counter = 0;
//		scanf("%d %d %d", &m, &Amin, &Amax);
//		printf("Case #%d:\n", i+1);
//		int first = ageAccu[Amin-1], last = ageAccu[Amax];
//		priority_queue<Person, vector<Person>, mycomparison> q(&people[first], &people[last]);
//		while (!q.empty() && counter < m) {
//			Person p = q.top();
//			printf("%s %d %d\n", p.name, p.age, p.wealth);
//			q.pop();
//			counter++;
//		}
//		if (counter == 0) {
//			printf("None\n");
//		}
//		printf("None\n");
//	}
//	return 0;
//}