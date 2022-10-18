#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
#include <memory.h>

using namespace std;
char s1[10005];
char s2[10005];
bool deleted[10005];

int main() {
    freopen("in.txt", "r", stdin);
    gets(s1);
    //getchar();
    gets(s2);
    //puts(s1);
    //puts(s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    sort(s2, s2+len2);
    //puts(s1);
    //puts(s2);
    memset(deleted, false, sizeof(deleted));
    for (int i = 0; i < len1; ++i) {
        if(binary_search(s2, s2+len2, s1[i])) {
            deleted[i] = true;
        }
    }
    for (int i = 0; i < len1; ++i) {
        if (!deleted[i]) {
            printf("%c", s1[i]);
        }
    }
    printf("\n");
    return 0;
}
