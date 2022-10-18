#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

bool isPrime(int x) {
   if (x < 2) {
       return false;
   } else if (x == 2 || x == 3) {
       return true;
   } else {
       for (int i = 2; i*i <= x; ++i) {
           if (x % i == 0) { return false; }
       }
       return true;
   }
}

bool isReversePrime(int x, int radix) {
    queue<int> q;
    while (x) {
        q.push(x % radix);
        x /= radix;
    }
    int reverseX = 0;
    while(!q.empty()) {
        reverseX = q.front() + reverseX * radix;
        q.pop();
    }
    return isPrime(reverseX);
}

int main(){
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    int x;
    do {
        cin >> x;
        if (x > 0) {
            int radix;
            cin >> radix;
            if (isPrime(x) && isReversePrime(x, radix)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    } while (x > 0);

    return 0;
}
