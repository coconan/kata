#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    // redirect
    //ifstream in("in.txt");
    //streambuf *cinbuf = cin.rdbuf();
    //cin.rdbuf(in.rdbuf());
    // redirect

    int k;
    vector<int> sequence;
    cin >> k;
    sequence.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> sequence[i];
    }
    int i, j, sum;
    int s = 0, e = 0, maxSum = -1;
    for (i = 0, j = 0, sum = 0; j < k; ) {
        sum += sequence[j++];
        if (sum > maxSum) {
            s = i; e = j; maxSum = sum;
        }
        if (sum < 0) {
            i = j; sum = 0;
        }
    }
    if (maxSum == -1) {
        cout << 0 << " " << sequence[0] << " " << sequence[k-1] << endl;
    } else {
        cout << maxSum << " " << sequence[s] << " " << sequence[e-1] << endl;
    }
    //cin.rdbuf(cinbuf);
    return 0;
}
