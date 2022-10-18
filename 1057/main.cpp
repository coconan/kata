#include <iostream>
#include <set>
#include <functional>
#include <stack>
#include <stdio.h>

using namespace std;

multiset<int, greater<int>> lower;
multiset<int> upper;
stack<int> s;
int n, key, mid;
char command[20];

int main() {

    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
         scanf("%s", command);
         if (command[1] == 'e') {
             if (s.empty()) {
                 printf("Invalid\n");
             } else {
                 //key = *lower.begin();
                 printf("%d\n", mid);
             }
         } else if (command[1] == 'o') {
             if (s.empty()) {
                 printf("Invalid\n");
             } else {
                 key = s.top();
                 s.pop();
                 printf("%d\n", key);
                 if (key > *lower.begin()) {
                    upper.erase(upper.find(key));
                 } else {
                    lower.erase(lower.find(key));
                 }
                 if (!s.empty()) {
                     if (upper.size() > lower.size()) {
                         lower.insert(*upper.begin());
                         upper.erase(upper.begin());
                     } else if (lower.size() > upper.size() + 1) {
                         upper.insert(*lower.begin());
                         lower.erase(lower.begin());
                     }
                     mid = *lower.begin();
                 }
             }
         } else {
             scanf("%d", &key);
             s.push(key);
             if (key > *lower.begin()) {
                upper.insert(key);
             } else {
                lower.insert(key);
             }
             if (upper.size() > lower.size()) {
                    lower.insert(*upper.begin());
                    upper.erase(upper.begin());
             } else if (lower.size() > upper.size() + 1) {
                    upper.insert(*lower.begin());
                    lower.erase(lower.begin());
             }
             mid = *lower.begin();
        }
//        cout << "lower: ";
//        for (multiset<int>::iterator it = lower.begin(); it != lower.end(); ++it) {
//            cout << *it << " ";
//        }
//        cout << "size: " << lower.size();
//        cout << endl;
//        cout << "upper: ";
//        for (multiset<int>::iterator it = upper.begin(); it != upper.end(); ++it) {
//            cout << *it << " ";
//        }
//        cout << "size: " << upper.size();
//        cout << endl;
    }
    return 0;
}
