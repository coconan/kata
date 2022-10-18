#include <iostream>
#include <cstdio>
#include <list>
#include <set>
#include <stdio.h>

using namespace std;

class Complex {
private:
	double real, image;
	static int count;
public:
	Complex() { updateCount(); }
	Complex(double r) { real = r; image = 0; }
	Complex(double r, double i) { real = r; image = i; }
	Complex(const Complex & c) {
		real = c.real;
		image = c.image;
		cout << "copy constructor called" << endl;
	}

	double getReal() { return real; }
	double getImage() { return image; }
	/*Complex & operator = (const Complex & c) {
		real = c.real;
		image = c.image;
		cout << "assignment" << endl;
		return * this;
	}*/

	Complex & operator = (const char * cValue) {
		char * pulsPtr;
		real = strtod(cValue, &pulsPtr);
		image = strtod(pulsPtr, NULL);
		return * this;
	}

	Complex operator * () {
		return * this;
	}

	static int updateCount() {
		count++;
		return count;
	}
};

class AA{};
class BB {
	AA v1, *v2;
	//BB v3;
	int v4;
};

int Complex::count;
union myun { struct { int x, y, z; } u; int k; } a; 

extern int i;
void sayHello();

int main() {
	Complex c1(5);
	Complex c2 = c1;
	a.u.x=4; a.u.y=5; a.u.z=6; a.k=0; printf("%d\n", a.u.x);
	sayHello();
	printf("%d\n", i);
	char* str = "12%f\n";
	printf("%s", str);
	printf(str);
	printf("%d\n");
	printf("precision=0 %.0d", 0);
	return 0;
}