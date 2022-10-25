#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addReverseNum(string num) {
     int carry = 0;
     string sum;
     for (int i = num.size()-1, j = 0; i >= 0; --i, ++j) {
          int d = num[i] -'0' + num[j] - '0' + carry;
          sum.push_back(d %10 +  '0');
          carry = d / 10;
     }
     if (carry != 0) {
         sum.push_back(carry + '0');
     }
     reverse(sum.begin(), sum.end());
     return sum;
}


bool isPalindrome(string num) {
    for (int i = 0; i < num.size() / 2; ++i) {
        if (num[i] != num[num.size()-1-i]) {
            return false;
        }
    }
    return true;
}



int main() {
    string n;
    int k;
    cin >> n >> k;
    int step;
    for (step = 0; step < k; ++step) {
        if (isPalindrome(n)) {
            break;
        }
        n = addReverseNum(n);
    }
    cout << n << endl;
    cout << step << endl;
    return 0;
}
