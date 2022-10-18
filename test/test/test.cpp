//#include <iostream>
//#include <cstdio>
//#include <list>
//#include <set>
//
//using namespace std;
//
//class Complex {
//private:
//	double real, image;
//	static int count;
//public:
//	Complex() { updateCount; }
//	Complex(double r, double i) { real = r; image = i; }
//	Complex(const Complex & c) {
//		real = c.real;
//		image = c.image;
//		cout << "copy constructor called" << endl;
//	}
//
//	double getReal() { return real; }
//	double getImage() { return image; }
//	/*Complex & operator = (const Complex & c) {
//		real = c.real;
//		image = c.image;
//		cout << "assignment" << endl;
//		return * this;
//	}*/
//
//	Complex & operator = (const char * cValue) {
//		char * pulsPtr;
//		real = strtod(cValue, &pulsPtr);
//		image = strtod(pulsPtr, NULL);
//		return * this;
//	}
//
//	Complex operator * () {
//		return * this;
//	}
//
//	static int updateCount() {
//		count++;
//		return count;
//	}
//};
//
//int Complex::count;
//
//class A {
//private:
//	int n;
//public:
//     void PrintN( ) const { cout << this->n << endl;}
//	 int GetN() { return n; }
//};
//
//class MyInt {
//	int nVal;
//public:
//	MyInt(int n) { nVal = n; }
//	int ReturnVal() { return nVal; }
//	MyInt & operator - (int rhs) {
//		nVal -= rhs;
//		return * this;
//	}
//};

//int main() {
//	Complex c1;
//	Complex c2 = c1;
//	Complex c3(c1);
//	Complex c4(3.0, 4.5);
//	Complex c5;
//	c5 = c4;
//	list<int> l1;
//	l1.push_back(1); l1.push_back(2);
//	list<int>::const_iterator i1, i2;
//	i1 = l1.begin(); i2 = l1.end();
//	set<int> myset; 
//	myset.insert(1);
//	myset.insert(2);
//	myset.insert(3);
//	set<int>::iterator si1, si2;
//	si1 = myset.begin();
//	si2 = si1++;
//
//	A a1;
//	const A a2;
//	a1.PrintN();
//
//	// a2 = a1;
//
//	c5 = * c4;
//	c5 = "";
//
//	int arr[3] = {1, 2, 3};
//	int & x = arr[2];
//	int & y = x;
//	y = 0;
//
//	cout << "x = " << x <<"\t arr[2] = " << arr[2] << endl;
//
//	cout << c5.getReal() << " " << c5.getImage() << endl;
//
//	MyInt objInt(10);
//	objInt-2-1-3;
//	cout << objInt.ReturnVal();
//	cout << ",";
//	objInt-2-1;
//	cout << objInt.ReturnVal() << endl;
//	return 0;
//}

#include <stdio.h>

int i = 127;

void sayHello() {
	printf("Hello\n");
}