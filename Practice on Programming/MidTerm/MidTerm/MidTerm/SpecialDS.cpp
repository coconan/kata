#include <iostream>
#include <set>
using namespace std;

template<class T, class Pred=less<T> >
class MySet: public multiset<T, Pred> {
public:
	MySet() {}

	template<class Iterator>
	MySet(Iterator first, Iterator last) {
		insert(first, last);
	}

	pair<typename MySet<T, Pred>::iterator, typename MySet<T, Pred>::iterator> FindInterval(const T& a, const T& b) {
		return make_pair(this->upper_bound(a), this->lower_bound(b));
	}
};

template<class Iterator>
void MyPrint(Iterator first, Iterator last) {
	Iterator temp = first;
	cout << *first << " ";
	for (Iterator iter = ++first; iter != last; ++iter) {
		if (*iter != *temp) {
			cout << *iter << " ";
		}
		temp = iter;
	}
}

//int main()
//{
//    int t;
//    cin >> t;
//    MySet<int> stInt;
//    int a[100];
//    while(t--) {
//    	int n;
//    	cin >> n;
//    	for(int i = 0;i < n; ++i )
//    		cin >> a[i];
//    	MySet<int> stInt(a,a+n);
//    	MyPrint(stInt.begin(),stInt.end()); //输出全部内容
//    	cout << endl;
//    	int s,e;
//    	cin >> s >> e; // 后面要输出位于 s 和 e 之间的元素
//    	pair<MySet<int>::iterator, MySet<int>::iterator> p;
//    	p  = stInt.FindInterval(s,e);
//    	if( p.first != p.second) {
//    		MyPrint(p.first,p.second);
//    		cout << endl;
//    	}
//    	else
//    		cout << "Interval Not Found" << endl;
//    	cin >> n;
//    	MySet<double,greater<double> > stDouble;
//    	for( int i = 0;i < n; ++i)	{
//    		double d;
//    		cin >> d;
//    		stDouble.insert(d);
//    	}
//    	MyPrint(stDouble.begin(),stDouble.end());
//    	cout << endl;
//    	double w;
//    	cin >> w;
//    	cout << * stDouble.upper_bound(w) << endl;
//    }
//}
