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

vector<Person> allAge[201];  // ÿ�������age�����������Ӧ��Person, ��allAge[1]��ageΪ1��Person
int currentAgeIndice[201];   // ÿ������Ӧ��allAge����һ��Ҫ���ʵ�����, ��currentAgeIndice[5]��Ӧ
                             // allAge[5]����һ����������, ÿ��query��Ҫ��ʼ��Ϊ0 

bool greaterThan(const Person a, const Person b) {  // sort��pred
	if (a.wealth == b.wealth) {
		if (a.age == b.age) {
			return strcmp(a.name, b.name) < 0;
		}
		return a.age < b.age;
	}
	return a.wealth > b.wealth;
}


struct Less  {                                 // priority_queue��pred
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
		allAge[p.age].push_back(p);                  // ��ÿ��Person�浽��Ӧ��allAge������
	}

	for (int i = 1; i < 201; i++) {
		if (allAge[i].size() > 0) {
			sort(allAge[i].begin(), allAge[i].end(), greaterThan);  // ��ÿ��age��������
		}
	}

	for (int i = 0; i < k; i++) {              // ����k������
		int m, Amin, Amax, counter = 0;
		scanf("%d %d %d", &m, &Amin, &Amax);
		printf("Case #%d:\n", i+1);

		memset(currentAgeIndice, 0, sizeof(currentAgeIndice));
		priority_queue<Person, vector<Person>, Less> q;  // �洢ÿ��age��greaterThan�������������Person
		for (int age = Amin; age <= Amax; age++) {            
			if (allAge[age].size() > 0) {
				q.push(allAge[age][currentAgeIndice[age]]);
				currentAgeIndice[age]++;
			}
		}

		while (!q.empty() && counter < m) {      // �ҳ�[Amin, Amax]��ǰm��Person, qΪ�����ʾ�Ҳ���m��Person
			p = q.top();                         // pΪ��δ��������Person
			printf("%s %d %d\n", p.name, p.age, p.wealth);
			q.pop();
			counter++;
			if (currentAgeIndice[p.age] < allAge[p.age].size()) { // ��allAge[p.age]��ȡ��һ��Person����q�У�
				q.push(allAge[p.age][currentAgeIndice[p.age]]);   // ͬʱ����currentAge[p.age]
				currentAgeIndice[p.age]++;
			}
		}

		if (counter == 0) {            // ����Ҫ���Person��Ϊ0
			printf("None\n");
		}
	}
	return 0;
}