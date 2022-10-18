#include <iostream>
using namespace std;

class Base {
public:
	virtual void Print() = 0;
};

class A: public Base {
private:
	int n;
public:
	A(int _n): n(_n) {}
	void Print() {
		cout << "A " << n << endl;
	}
};

class B: public Base {
private:
	int n;
public:
	B(int _n): n(_n) {}
	void Print() {
		cout <<"B " << n << endl;
	}
};

void PrintInfo(Base * o) {
	o->Print();
}

Base * a[101];

//int main()
//{
//    int t;
//    cin >> t;
//    while( t -- ) {
//    	int n;
//    	cin >> n;
//    	for( int i = 0;i < n; ++i)	{
//    		char c; int k;
//    		cin >> c >> k;
//    		if( c == 'A')
//    			a[i] = new A(k);
//    		else
//    			a[i] = new B(k);
//    	}
//    	cout << n << endl;
//    	for( int i = 0;i < n; ++i)
//    		PrintInfo(a[i]);
//    	cout << "****" << endl;
//    }
//}
