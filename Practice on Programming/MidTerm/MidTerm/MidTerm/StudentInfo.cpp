#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int score;
    Student(int id_,const string & nm,int sc):
    	id(id_),name(nm),score(sc) { }
    Student() { }
};


struct Info
{
    string name;
    int score;
    Info(const string & s,int sc):name(s),score(sc) { }
};

pair<int, Info> MyMakePair(Student& st) {
	return make_pair(st.id, Info(st.name, st.score));
}

Student MyFind(map<int, Info>& mp, int n) {
	map<int, Info>::iterator iter = mp.begin();
	while (iter != mp.end()) {
		if ((*iter).first == n) break;
		++iter;
	}
	return Student(n, (*iter).second.name, (*iter).second.score);
}

//int main()
//{
//    std::map<int,Info>  mp;
//    int t;
//    cin >> t;
//    while( t -- ) {
//    	mp.clear();
//    	int n;
//    	cin >> n;
//    	Student st;
//    	for( int i = 0;i < n; ++i) {
//    		cin >> st.id >> st.name >> st.score;
//    		mp.insert(MyMakePair(st));
//    	}
//    	cin >> n;
//		
//    	st = MyFind(mp, n);
//    	cout << st.name << " " << st.score  << endl;
//    }
//    return 0;
//}
