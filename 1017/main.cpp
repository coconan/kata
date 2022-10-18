#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

struct Customer {
    int arriveHour, arriveMinute, arriveSecond;
    int processingTime;
    Customer(int _h, int _m, int _s, int _t)
        :arriveHour(_h), arriveMinute(_m), arriveSecond(_s), processingTime(_t) {};
};

class Comparator {
public:
    bool operator()(const Customer &a, const Customer &b) {
        if (a.arriveHour == b.arriveHour) {
            if (a.arriveMinute == b.arriveMinute) {
                return a.arriveSecond > b.arriveSecond;
            }
            return a.arriveMinute > b.arriveMinute;
        }
        return a.arriveHour > b.arriveHour;
    }
};

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(1);
    int n, k;
    vector<Customer> customers;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int h, m, s, t;
        char c;
        cin >> h >> c;
        cin >> m >> c;
        cin >> s >> t;
        customers.push_back(Customer(h, m, s, t));
    }
    sort(customers.begin(), customers.end(), Comparator());

    int openTime = 8 * 3600;
    vector<int> windowsTime(k, openTime);
    int  waitingTime = 0;

    while (true) {
        int minTime = 10000000, w = 0;
        for (int i = 0; i < k; ++i) {
            if (windowsTime[i] < minTime) {
                minTime = windowsTime[i];
                w = i;
            }
        }

        if (customers.empty()) { break; }
        Customer nextCustomer = customers.back();
        int arriveTime = nextCustomer.arriveHour * 3600 + nextCustomer.arriveMinute * 60
            + nextCustomer.arriveSecond;
        if (arriveTime > 17*3600) { break; }
        if (windowsTime[w] > arriveTime) {          // !!!!!!!!!!!!!!
            waitingTime += windowsTime[w] - arriveTime;
            windowsTime[w] += nextCustomer.processingTime * 60;
        } else {
            windowsTime[w] = arriveTime + nextCustomer.processingTime * 60;
        }
        customers.pop_back();
    }
    if (customers.size() != n) {
        float averageWaitingTime = waitingTime / 60.0 / (n - customers.size());
        cout << averageWaitingTime << endl;
    } else {
        cout << "0.0" << endl;
    }
    return 0;
}
