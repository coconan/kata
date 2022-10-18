#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>

using namespace std;

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    queue< pair<int, int> > customers;
    for (int i = 0; i < k; ++i) {
        int processingTime;
        cin >> processingTime;
        customers.push(make_pair(i, processingTime));
    }
//    for (; !customers.empty(); customers.pop()) {
//        pair<int, int> cu = customers.front();
//        cout << cu.first << " " << cu.second << endl;
//    }
    vector< queue< pair<int, int> > > windows;
    windows.resize(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (customers.empty()) { break; }
            windows[j].push(customers.front());
            //cout << customers.front().first << " ";
            customers.pop();
        }
        //cout << endl;
    }
    vector<int> windowTime(n, 0), servedTime(k, -1), finishedTime(k, -1);
    while(true) {
        int minFinishedTime = 1000000, nextWin;
        bool allEmpty = true;
        for (int i = 0; i < n; ++i) {
            if (!windows[i].empty()) {
                allEmpty = false;
                int time = windowTime[i] + windows[i].front().second;
                if (time < minFinishedTime) {
                    minFinishedTime = time;
                    nextWin = i;
                }
            }
        }
        //cout << nextWin << endl;
        if (allEmpty) break;
        pair<int, int> finishedCustomer = windows[nextWin].front();
        servedTime[finishedCustomer.first] = windowTime[nextWin];
        finishedTime[finishedCustomer.first] = minFinishedTime;
        windowTime[nextWin] = minFinishedTime;
        windows[nextWin].pop();
        if (!customers.empty()) {
            windows[nextWin].push(customers.front());
            customers.pop();
        }
    }

    for (int i = 0; i < q; ++i) {
        int customer;
        cin >> customer;
        if (servedTime[customer-1] / 60 + 8 < 17) {
            int finishedHour = finishedTime[customer-1] / 60 + 8;
            int finishedMinute = finishedTime[customer-1] % 60;
            cout << setw(2) << setfill('0') << finishedHour << ":"
                 << setw(2) << setfill('0') << finishedMinute << endl;
        } else {
            cout << "Sorry" << endl;
        }
    }

    return 0;
}
