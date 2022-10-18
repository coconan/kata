#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    float game[3][3], maxOdds[3];
    char maxResults[3], results[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; ++i) {
        maxOdds[i] = 0.0;
        for (int j = 0; j < 3; ++j) {
            cin >> game[i][j];
            if (maxOdds[i] < game[i][j]) {
                maxOdds[i] = game[i][j];
                maxResults[i] = results[j];
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        cout << maxResults[i] << " ";
    }
    cout << (maxOdds[0] * maxOdds[1] * maxOdds[2] * 0.65 - 1) * 2 << endl;
    return 0;
}
