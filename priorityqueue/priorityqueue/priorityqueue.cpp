#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct node {
     int year;
     int month;
     int day;
};

struct cmp {
     bool operator() (const node &a, const node &b)
     {
         if (a.year == b.year) {
			if (a.month == b.month) {
				return a.day <= b.day;
			}
			return a.month < b.month;
		 }
		 return a.year < b.year;
     }
};

priority_queue<node, vector<node>, cmp> p;
void slove(int n)
{
     while (n--)
     {
         node e = p.top();
         p.pop();
		 printf("%d %d %d\n", e.year, e.month, e.day);
     }
}

int main()
{
     node a;
	 int n;
     char s[100];
	 scanf("%d", &n);
     for (int i=0; i < n; i++)
     {
		 scanf("%d %d %d", &a.year, &a.month, &a.day);
         p.push(a);
     }
     slove(n);

     return 0;
}