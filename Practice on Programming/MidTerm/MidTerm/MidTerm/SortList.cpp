#include <iostream>
#include <list>
using namespace std;

class MyLess {
public:
	bool operator()(int a, int b) {
		if (a%10 == b%10) return a > b;
		else return a%10 > b%10;
	}
};


//int main()
//{
//    int t;
//    cin >> t;
//    list<int> lst;
//    while( t--) {
//    	int n;
//    	cin >> n;
//    	lst.clear();
//    	int m;
//    	for( int i = 0;i < n; ++i) {
//    		cin >> m;
//    		lst.push_back(m);
//    	}
//    	lst.sort(MyLess());
//    	list<int>::iterator it;
//    	for( it = lst.begin(); it != lst.end(); ++ it) {
//    		cout << * it  << " ";
//    	}
//    	cout << endl;
//    }
//    return 0;
//}