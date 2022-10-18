#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class MyClass {
	vector<T> arr;
public:
	MyClass(T* begin, int n): arr(n) {
		copy(begin, begin+n, arr.begin());
	}

	void List() {
		vector<T>::const_iterator i;
		for (i = arr.begin(); i != arr.end(); ++i) {
			cout << * i << ", ";
		}
	}
};

int main() {
	string arr[4] = {"Tom", "Jack", "Mary", "John"};
	MyClass<string> obj(arr, 4);
	obj.List();
	return 0;
}