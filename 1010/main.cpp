#include <cstring>
#include <memory.h>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int char2int(char c) {
   return ('0' <= c && c <= '9') ? c - '0' : c - 'a' + 10;
}

int findMaxDigit(char n[], int len) {
    int maxDigit = 0, digit;
    for (int i = 0; i < len; ++i) {
	    digit = char2int(n[i]);
        if (maxDigit < digit) {
            maxDigit = digit;
        }
    }
    return maxDigit;
}

unsigned long long stringToInt(char n[], int len, unsigned long long base) {
    unsigned long long num = 0, m = 1;
    for (int i = len-1; i >= 0; --i) {
        num += char2int(n[i]) * m;
        m *= base;
    }
    return num;
}

unsigned long long
binSearch(char n[], int len, unsigned long long lower,
          unsigned long long upper, unsigned long long value) {
    unsigned long long num = 0, power = 1, mid;
    bool found = false;
    while (lower <= upper) {
        num = 0; power = 1;
        mid = (lower + upper) / 2;
        for (int i = len-1; i >= 0; --i) {
            num += char2int(n[i]) * power;
            power *= mid;
            if (num > value) { break; }   // avoiding overflow
        }
        if (value < num) {
            upper = mid - 1;
        } else if (value > num) {
            lower = mid + 1;
        } else {
            found = true;
            break;
        }
    }

    return found ? mid : -1;
}


int main() {
   char n1[15], n2[15];
    int tag, len1, len2;
    unsigned long long num1, num2, upper, lower, radix, ans;
    bool found = false;
    scanf("%s %s %d %ld", n1, n2, &tag, &radix);
    len1 = strlen(n1);
    len2 = strlen(n2);
    if (tag == 1) {
        num1 = stringToInt(n1, len1, radix);
        lower = findMaxDigit(n2, len2) + 1;
        upper = (num1 + 1 > lower + 1) ? num1 +1 : lower +1;
        ans = binSearch(n2, len2, lower, upper, num1);
    } else {
        num2 = stringToInt(n2, len2, radix);
        lower = findMaxDigit(n1, len1) + 1;
        upper = (num2 + 1 > lower + 1) ? num2 +1 : lower +1;
        ans = binSearch(n1, len1, lower, upper, num2);
    }
    if (ans != -1) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
