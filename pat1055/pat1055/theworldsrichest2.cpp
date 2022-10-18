#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <iostream>
#include <memory.h>

using namespace std;

struct Person {
	int age, wealth;
	char name[10];
};

vector<Person> allAge[201];  // 每个数组存age与其索引相对应的Person, 如allAge[1]存age为1的Person
int currentAgeIndice[201];   // 每个数对应于allAge中下一个要访问的索引, 如currentAgeIndice[5]对应
                             // allAge[5]的下一个访问索引, 每次query都要初始化为0 

bool greaterThan(const Person a, const Person b) {  // sort的pred
	if (a.wealth == b.wealth) {
		if (a.age == b.age) {
			return strcmp(a.name, b.name) < 0;
		}
		return a.age < b.age;
	}
	return a.wealth > b.wealth;
}


struct Less  {                                 // priority_queue的pred
  bool operator() (const Person& a, const Person& b)
  {
    if (a.wealth == b.wealth) {
		if (a.age == b.age) {
			return strcmp(a.name, b.name) > 0;
		}
		return a.age > b.age;
	}
	return a.wealth < b.wealth;
  }
};

int main() {
	// freopen("data.in", "r", stdin);
	int n, k;  // n people, k queries
	Person p;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", p.name, &p.age, &p.wealth);
		allAge[p.age].push_back(p);                  // 将每个Person存到对应的allAge数组中
	}

	for (int i = 1; i < 201; i++) {
		if (allAge[i].size() > 0) {
			sort(allAge[i].begin(), allAge[i].end(), greaterThan);  // 对每个age进行排序
		}
	}

	for (int i = 0; i < k; i++) {              // 处理k次请求
		int m, Amin, Amax, counter = 0;
		scanf("%d %d %d", &m, &Amin, &Amax);
		printf("Case #%d:\n", i+1);

		memset(currentAgeIndice, 0, sizeof(currentAgeIndice));
		priority_queue<Person, vector<Person>, Less> q;  // 存储每个age的greaterThan函数排序的最大的Person
		for (int age = Amin; age <= Amax; age++) {            
			if (allAge[age].size() > 0) {
				q.push(allAge[age][currentAgeIndice[age]]);
				currentAgeIndice[age]++;
			}
		}

		while (!q.empty() && counter < m) {      // 找出[Amin, Amax]中前m个Person, q为空则表示找不到m个Person
			p = q.top();                         // p为还未输出的最大Person
			printf("%s %d %d\n", p.name, p.age, p.wealth);
			q.pop();
			counter++;
			if (currentAgeIndice[p.age] < allAge[p.age].size()) { // 从allAge[p.age]中取下一个Person放入q中，
				q.push(allAge[p.age][currentAgeIndice[p.age]]);   // 同时更新currentAge[p.age]
				currentAgeIndice[p.age]++;
			}
		}

		if (counter == 0) {            // 符合要求的Person数为0
			printf("None\n");
		}
	}
	return 0;
}