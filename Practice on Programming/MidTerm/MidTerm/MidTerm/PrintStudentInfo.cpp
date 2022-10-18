#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int id;
public:
	Student() {}
	Student(string _name, int _id): name(_name), id(_id) {}
	void Read() {
		cin >> name >> id;
	}
	void Print() {
		cout << id << " " << name << endl;
	}
};


//int main()
//{
//    int t;
//    cin >> t;
//    Student s("Tom",12);
//    while( t-- )	{
//    	int n;
//    	cin >> n;
//    	Student st;
//    	for( int i = 0;i < n; ++i) {
//    		st.Read();
//    		st.Print();
//    	}
//    	cout << "****" << endl;
//    }
//    return 0;
//}
