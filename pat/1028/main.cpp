#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

struct Record {
    char id[8];
    char name[10];
    int grade;
};

bool cmp1(const Record &a, const Record &b) {
    return strcmp(a.id, b.id) < 0;
}

bool cmp2(const Record &a, const Record &b) {
    int r = strcmp(a.name, b.name);
    if (r == 0) {
        return strcmp(a.id, b.id) < 0;
    }
    return r < 0;
}

bool cmp3(const Record &a, const Record &b) {
    if (a.grade == b.grade) {
        return strcmp(a.id, b.id) < 0;
    }
    return a.grade < b.grade;
}

int main() {
    //ifstream in("in2.txt");
    //cin.rdbuf(in.rdbuf());
    freopen("in2.txt", "r", stdin);
    int n, c;
    scanf("%d%d",&n,&c);
    vector<Record> rs;
    for (int i = 0; i <n; ++i) {
        Record r;
        scanf("%s %s %d", r.id, r.name, &r.grade);
        rs.push_back(r);
    }
    if (c == 1 ) {
        sort(rs.begin(), rs.end(), cmp1);
    } else if (c == 2) {
        sort(rs.begin(), rs.end(), cmp2);
    } else {
        sort(rs.begin(), rs.end(), cmp3);
    }
    for (int i = 0; i < n; ++i) {
        printf("%s %s %d\n",rs[i].id, rs[i].name, rs[i].grade);
    }
    return 0;
}
