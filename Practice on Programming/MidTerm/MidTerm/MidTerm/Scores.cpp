#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
private:
	string name;
	int score;
public:
	Student(): name(""), score(-1) {}
	Student(const Student& other): name(other.name), score(other.score) {}
	bool operator<(const Student& that) const {
		return score < that.score;
	}
	friend istream& operator>>(istream& is, Student& s) {
		is >> s.name >> s.score;
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& s) {
		os << s.name;
		return os;
	}
};

//int main()
//{
//    int t;
//    vector<Student> v;
//    cin >> t;
//
//    while( t--) {
//    	int n;
//    	cin >> n;
//    	Student st;
//    	v.clear();
//    	for( int i = 0;i < n; ++i ) {
//    		cin >> st;
//    		v.push_back(st);
//    	}
//    	sort(v.begin(),v.end());
//    	for( int i = 0;i < v.size(); ++ i)
//    		cout << v[i] << endl;
//    	cout << "****" << endl;
//    }
//    return 0;
//}
