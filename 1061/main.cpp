#include <iostream>
#include <fstream>

using namespace std;

char *weekday[8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    fstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    bool first = true;
    int i = 0;
    for (i = 0; i < s1.size() && i < s2.size(); ++i) {
        if (s1[i] == s2[i] && 'A' <= s1[i] && s1[i] <= 'G') {
            cout << weekday[s1[i]-'A'] << " ";
            break;
        }
    }
    for (++i; i < s1.size() && i < s2.size(); ++i) {
        if (s1[i] == s2[i]) {
            if ('0' <= s1[i] && s1[i] <= '9') {
                cout << '0' << s1[i] - '0';
                break;
            } else if ('A' <= s1[i] && s1[i] <= 'N') {
                cout << s1[i] - 'A' + 10;
                break;
            }
        }
    }

    for (i = 0; i < s3.size() && i < s4.size(); ++i) {
        if (s3[i] == s4[i] && (s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')) {
            cout << ":" << i/10 << i%10 << endl;
            break;
        }
    }
    return 0;
}
