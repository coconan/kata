#include <iostream>

using namespace std;

int main() {
    int n, i = 0;
    cin >> n;
    while (i < n) {
        i++;
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if ((a >= 0 && b >= 0 && c >= 0) || (a < 0 && b < 0 && c < 0)) {
            if (a > (c - b)) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        } else if ((a < 0 && b >= 0) || (a >= 0 && b < 0)) {
            if (a + b > c) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        } else if ((a >= 0 && b >= 0 && c < 0)) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    return 0;
}
