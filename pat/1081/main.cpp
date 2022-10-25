#include <iostream>
#include <stdio.h>

#define ABS(a)  ((a<0) ? (-a) : (a))

using namespace std;

int gcd(int a, int b) {
   int temp = a;
   while (b) {
       temp = a;
       a = b;
       b = temp % b;
   }
   return a;
}

int main() {
    int n;
    scanf("%d", &n);
    int num1, deno1, num2, deno2;
    scanf("%d/%d", &num1, &deno1);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d/%d", &num2, &deno2);
        num1 = num1 * deno2 + num2 * deno1;
        deno1 = deno1 * deno2;
        int g = gcd(ABS(num1), deno1);
        num1 = num1 / g;
        deno1 = deno1 / g;
    }
    int integer = num1 / deno1;
    if (num1 == 0) {
        printf("0");
    } else {
        if (integer) {
            printf("%d",integer);
        }
        if (num1 % deno1) {
            if (integer) {
                printf(" ");
            }
            printf("%d/%d", ABS(num1 % deno1), deno1);
        }
    }
    return 0;
}
