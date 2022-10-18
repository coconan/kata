#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    static int count;
public:
	static void InitCount() {
		count = 0;
	}
	Student() { count++; }
	Student(int n): id(10) { count++; }
	Student(const Student& other) { id = other.id; count++; }
	friend void PrintCount();
	friend void Print(Student s);
	~Student() { --count; }
	
};

int Student::count;
void PrintCount() {
    cout << "Total " << Student::count << " students" << endl;
}
void Print(Student s)
{
    cout << "the id is " << s.id << endl;
}

int main()
{
    Student::InitCount();
    Student s;
    PrintCount();
    Student s1(10);
    Student s2(s1);
    PrintCount();
    Print(s2);
    PrintCount();
    return 0;
}
