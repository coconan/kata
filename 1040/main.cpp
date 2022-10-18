#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char str[10005];

int main() {
    freopen("in.txt", "r", stdin);
    gets(str);
    puts(str);
    int slen = strlen(str);
    int maxlen = 0;
    for (int i = 0; i < slen; ++i) {
        int j = 1, len = 1;
        while (i-j >= 0 && i+j < slen && str[i-j] == str[i+j]) {
            len += 2; j++;
        }
        if (len > maxlen) { maxlen = len; }
        j = 0; len = 0;
        while (i-j >= 0 && i+j+1 < slen && str[i-j] == str[i+j+1]) {
            len += 2; j++;
        }
        if (len > maxlen) { maxlen = len; }
    }
    printf("%d\n", maxlen);
    return 0;
}
