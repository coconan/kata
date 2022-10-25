#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

struct Student {
    int id, c, m, e;
    float a;
};

class Ccomparator {
public:
    bool operator()(const Student &a, const Student &b) {
        return a.c > b.c;
    }
};

class Mcomparator {
public:
    bool operator()(const Student &a, const Student &b) {
        return a.m > b.m;
    }
};

class Ecomparator {
public:
    bool operator()(const Student &a, const Student &b) {
        return a.e > b.e;
    }
};

class Acomparator {
public:
    bool operator() (const Student &a, const Student &b) {
        return a.a > b.a;
    }
};

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    vector< Student > students;
    map<int, pair<char, int> > studentsRank;
    int n, m;
    cin >> n >> m;
    students.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].c >> students[i].m >> students[i].e;
        students[i].a = (students[i].c + students[i].m + students[i].e) / 3;
        studentsRank.insert(pair<int, pair<char, int>>(students[i].id, pair<char, int>('\0', 10000000)));
    }

    sort(students.begin(), students.end(), Acomparator());
    for (int i = 0, score = -1, rank = 0; i < n; ++i) {
        if (students[i].a != score) { rank = i + 1; }
        score = students[i].a;
        int id = students[i].id;
        if (studentsRank[id].second > rank) {
            studentsRank[id] = pair<char, int>('A', rank);
        }
    }

    sort(students.begin(), students.end(), Ccomparator());
    for (int i = 0, score = -1, rank = 0; i < n; ++i) {
        if (students[i].c != score) { rank = i + 1; }
        score = students[i].c;
        int id = students[i].id;
        if (studentsRank[id].second > rank) {
            studentsRank[id] = pair<char, int>('C', rank);
        }
    }

    sort(students.begin(), students.end(), Mcomparator());
    for (int i = 0, score = -1, rank = 0; i < n; ++i) {
        if (students[i].m != score) { rank = i + 1; }
        score = students[i].m;
        int id = students[i].id;
        if (studentsRank[id].second > rank) {
            studentsRank[id] = pair<char, int>('M', rank);
        }
    }

    sort(students.begin(), students.end(), Ecomparator());
    for (int i = 0, score = -1, rank = 0; i < n; ++i) {
        if (students[i].e != score) { rank = i + 1; }
        score = students[i].e;
        int id = students[i].id;
        if (studentsRank[id].second > rank) {
            studentsRank[id] = pair<char, int>('E', rank);
        }
    }
    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;
        if (studentsRank.count(id)) {
            cout << studentsRank[id].second << " " << studentsRank[id].first << endl;
        } else {
            cout << "N/A" << endl;
        }
    }
    return 0;
}
