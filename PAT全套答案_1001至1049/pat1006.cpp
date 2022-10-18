#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

struct Person
{
	string id;
	string in;
	string out;
};

vector<Person>p;

bool cmp1(Person a,Person b)
{
	return a.in<b.in;
}

bool cmp2(Person a,Person b)
{
	return a.out>b.out;
}

int main()
{
	//freopen("D://test.txt","r",stdin);
	int n;
	cin>>n;
	p.clear();
	for(int i=0;i<n;i++)
	{
		Person buf;
		cin>>buf.id>>buf.in>>buf.out;
		p.push_back(buf);
	}
	sort(p.begin(),p.end(),cmp1);
	cout<<p[0].id<<" ";
	sort(p.begin(),p.end(),cmp2);
	cout<<p[0].id<<endl;
	return 0;
}
