#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Record {
    string name;
    string time;
    string action;
};
struct Call {
    string s, e;
    int duration;
    float fee;
    Call(string _s, string _e, int _duration, float _fee)
        : s(_s), e(_e), duration(_duration), fee(_fee) {}
};

struct Bill {
    string name, month;
    vector<Call> calls;
    float total;
    Bill(string _name, string _month, Call call, float _total): name(_name), month(_month), total(_total) {
        calls.push_back(call);
    }
};

class Comparator {
public:
    bool operator()(const Record &a, const Record &b) {
        if (a.name == b.name) {
            return a.time < b.time;
        }
        return a.name < b.name;
    }
};

float computeFeeFromBegining(int t, vector<int> &toll) {
    int hours = t / 60, minutes = t % 60;
    float fee = 0.0;
    for (int i = 0; i < hours; ++i) {
        fee += toll[i%24] * 60;
    }
    fee += toll[hours%24] * minutes;
    return fee;
}

Call computeCall(Record &a, Record &b, vector<int> &toll) {
    int day1, day2, hour1, hour2, minute1, minute2, duration = 0;
    day1 = (a.time[3] - '0') * 10 + a.time[4] - '0';
    day2 = (b.time[3] - '0') * 10 + b.time[4] - '0';
    hour1 = (a.time[6] - '0') * 10 + a.time[7] - '0';
    hour2 = (b.time[6] - '0') * 10 + b.time[7] - '0';
    minute1 = (a.time[9] - '0') * 10 + a.time[10] - '0';
    minute2 = (b.time[9] - '0') * 10 + b.time[10] - '0';
    int t1 = day1 * 24 * 60 + hour1 * 60 + minute1;
    int t2 = day2 * 24 * 60 + hour2 * 60 + minute2;
    float fee = computeFeeFromBegining(t2, toll) - computeFeeFromBegining(t1, toll);
    duration += t2 - t1;
    return Call(a.time.substr(3), b.time.substr(3), duration, fee/100.0);;
}

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    vector<int> toll(24, 0);
    for (int i = 0; i < 24; ++i) {
        cin >> toll[i];
    }
    vector<Record> records;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Record r;
        cin >> r.name >> r.time >> r.action;
        records.push_back(r);
    }
    sort(records.begin(), records.end(), Comparator());

    vector<Bill> bills;
    for (int i = 0; i < n-1; ) {
        Record cur = records[i], next = records[i+1];
        if (cur.name == next.name && cur.action == "on-line"
            && next.action == "off-line") {
            i += 2;
            Call call = computeCall(cur, next, toll);
            if (bills.size() == 0 || bills.back().name != cur.name) {
                Bill b(cur.name, cur.time.substr(0, 2), call, call.fee);
                bills.push_back(b);
            } else {
                bills.back().calls.push_back(call);
                bills.back().total += call.fee;
            }
        } else {
            ++i;
        }
    }

    for (vector<Bill>::iterator it = bills.begin(); it != bills.end(); ++it) {
        cout << (*it).name << " " << (*it).month << endl;
        for (vector<Call>::iterator cit = (*it).calls.begin(); cit != (*it).calls.end(); ++cit) {
            cout << (*cit).s << " " << (*cit).e << " " << (*cit).duration
                 << " $" << (*cit).fee << endl;
        }
        cout << "Total amount: $" << (*it).total << endl;
    }

    return 0;
}
