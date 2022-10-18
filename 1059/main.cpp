#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>

using namespace std;


int main() {
    long n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1=1\n");
    } else {
        printf("%d=", n);
        int prime[100], expo[100] = {0}, nfactor = 0;
        for (int i = 2; i < int(sqrt(n)) + 1; ++i) {
            int p = 0;
            while (n % i == 0) {
                p++;
                n /= i;
            }
            if (p != 0) {
                prime[nfactor] = i;
                expo[nfactor++] = p;
            }
        }
        if (n != 1) {
            prime[nfactor] = n;
            expo[nfactor++] = 1;
        }

        if (expo[0] == 1) { printf("%d", prime[0]); }
        else { printf("%d^%d", prime[0], expo[0]); }
        for (int i = 1; i < nfactor; ++i) {
            if (expo[i] == 1) { printf("*%d", prime[i]); }
            else { printf("*%d^%d", prime[i], expo[i]); }
        }
    }
    return 0;
}
