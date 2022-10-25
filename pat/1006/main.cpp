#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Record {
    string id, signInTime, signOutTime;
};

int main()
{
    //ifstream in("in.txt");
    //streambuf *cinbuf = cin.rdbuf();
    //cin.rdbuf(in.rdbuf());
    int m;
    string unlocker, unlockTime, locker, lockTime;
    cin >> m;
    cin >> unlocker >> unlockTime >> lockTime;
    locker = unlocker;
    for (int i = 1; i < m; ++i) {
        Record record;
        cin >> record.id >> record.signInTime >> record.signOutTime;
        if (record.signInTime < unlockTime) {
            unlocker = record.id;
            unlockTime = record.signInTime;
        }
        if (record.signOutTime > lockTime) {
            locker = record.id;
            lockTime = record.signOutTime;
        }
    }
    cout << unlocker << " " << locker << endl;
    //cin.rdbuf(cinbuf);
    return 0;
}
