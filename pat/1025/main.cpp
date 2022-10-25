#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Testee {
    string regNo;
    int finalRank;
    int localRank;
    int localNo;
    int score;
};

bool cmp(const Testee &a, const Testee &b) {
    if (a.score == b.score) {
        return a.regNo < b.regNo;
    }
    return a.score > b.score;
}

int main() {
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector<Testee> testees;
    int s = 0, e = 0;
    for (int localNo = 1; localNo <= n; ++localNo) {
        s = e;
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i, ++e) {
            Testee t;
            cin >> t.regNo >> t.score;
            t.localNo = localNo;
            testees.push_back(t);
        }
        sort(testees.begin()+s, testees.end(), cmp);
        int rank = 0, score = -1;
        for (int i = s, j = 0; i < e; ++i, ++j) {
            if (testees[i].score != score) {
                score = testees[i].score;
                rank = j + 1;
            }
            testees[i].localRank = rank;
        }
//        for (int i = s; i < e; ++i) {
//            cout << testees[i].regNo << " " << testees[i].score << " "
//                 << testees[i].localNo << " " << testees[i].localRank << endl;
//        }
    }

    sort(testees.begin(), testees.end(), cmp);
    int rank = 0, score = -1;
    for (int i = 0; i < e; ++i) {
         if (testees[i].score != score) {
            score = testees[i].score;
            rank = i + 1;
        }
        testees[i].finalRank = rank;
    }
    cout << e << endl;
    for (int i = 0; i < e; ++i) {
        cout << testees[i].regNo << " ";
        cout << testees[i].finalRank << " ";
        cout << testees[i].localNo << " ";
        cout << testees[i].localRank << endl;
    }
    return 0;
}
