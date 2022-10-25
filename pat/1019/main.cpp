#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n, b;
    cin >> n >> b;
    if (n == 0) {
        cout << "Yes\n" << "0\n";
    } else {
        vector<long long> v;
        while (n) {
            v.push_back(n % b);
            n /= b;
        }
        bool isPalin = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != v[v.size()-1-i]) {
                isPalin = false;
                break;
            }
        }
        if (isPalin) { cout << "Yes\n"; }
        else         { cout << "No\n"; }
        cout << v[v.size()-1];
        for (int i = v.size()-2; i >= 0; --i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}
