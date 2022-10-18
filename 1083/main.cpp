#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string name;
    string id;
    int grade;
    Student(string _name, string _id, int _grade): name(_name), id(_id), grade(_grade) {}
};

class Greater {
public:
    bool operator()(const Student &a, const Student &b) {
        return a.grade > b.grade;
    }
};



int main() {
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector<Student> ss;
    for (int i = 0; i < n; ++i) {
        Student s("", "", -1);
        cin >> s.name >> s.id >> s.grade;
        ss.push_back(s);
    }
    sort(ss.begin(), ss.end(), Greater());
//    for (int i = 0; i < n; ++i) {
//        cout << ss[i].name << " " << ss[i].id << " " << ss[i].grade << endl;
//    }
    int g1, g2;
    cin >> g1 >> g2;

    Student lower("", "", g2);
    Student upper("", "", g1);
    vector<Student>::iterator lo = lower_bound(ss.begin(), ss.end(), lower, Greater());
    vector<Student>::iterator hi = upper_bound(ss.begin(), ss.end(), upper, Greater());
    if (lo != hi) {
        for (vector<Student>::iterator it = lo; it != hi; ++it) {
           cout << (*it).name << " " << (*it).id << endl;
        }
    } else {
        cout << "NONE\n";
    }
    return 0;
}
