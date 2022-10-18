#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;
struct Person {
     char name[10];
     int age;
     int wealth;
};

class Less {
public:
    bool operator() (const Person &a, const Person &b) {
        if (a.wealth == b.wealth) {
        if (a.age == b.age) {
            return strcmp(a.name, b.name) > 0;
            }
            return a.age > b.age;
        }
        return a.wealth < b.wealth;
    }
};

vector<Person> pbyage[201];
int nextpbyage[201];
int n, k, counter;

bool cmp(const Person &a, const Person &b) {
    if (a.wealth == b.wealth) {
        if (a.age == b.age) {
            return strcmp(a.name, b.name) < 0;
        }
        return a.age < b.age;
    }
    return a.wealth > b.wealth;
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        Person p;
        scanf("%s %d %d", p.name, &p.age, &p.wealth);
        pbyage[p.age].push_back(p);
    }
    for (int i = 1; i < 201; ++i) {
        sort(pbyage[i].begin(), pbyage[i].end(), cmp);
    }
    for (int i = 1; i <= k; ++i) {
        printf("Case #%d:\n", i);
        int m, Amin, Amax;
        scanf("%d %d %d", &m, &Amin, &Amax);
        memset(nextpbyage, 0, sizeof(nextpbyage));
        priority_queue<Person, vector<Person>, Less> q;
        for (int j = Amin; j <= Amax; j++) {
            if (nextpbyage[j] < pbyage[j].size()) {
                 q.push(pbyage[j][nextpbyage[j]++]);
            }
        }
        for (counter = 0; counter < m; ++counter) {
            if (q.empty()) {
                break;
            } else {
                Person p = q.top();
                q.pop();
                printf("%s %d %d\n", p.name, p.age, p.wealth);
                if (nextpbyage[p.age] < pbyage[p.age].size()) {
                    q.push(pbyage[p.age][nextpbyage[p.age]++]);
                }
            }
        }
        if (counter == 0) {
            printf("None\n");
        }
    }
    return 0;
}
