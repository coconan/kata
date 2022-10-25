#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char str[100];
    scanf("%s", str);
    int slen = strlen(str);
    int n1 = (slen+2) / 3;
    int n2 = (slen+2) / 3;
    int n3 = slen+2 - n1 - n2;
    int i, j;
    for (i = 0, j = slen-1; j - i >= n3; i++, j--) {
        printf("%c", str[i]);
        for (int k = 0; k < n3 - 2; ++k) {
            printf(" ");
        }
        printf("%c\n", str[j]);
    }
    for ( ; i <= j; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
