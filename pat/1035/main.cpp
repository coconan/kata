#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream in("in3.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector< pair<string, string> > accounts;
    for (int i = 0; i < n; ++i) {
        string username, password;
        bool modified = false;
        cin >> username >> password;
        for (int i = 0; i < password.size(); ++i) {
            switch(password[i]) {
            case '0': password[i] = '%'; modified = true; break;
            case '1': password[i] = '@'; modified = true; break;
            case 'l': password[i] = 'L'; modified = true; break;
            case 'O': password[i] = 'o'; modified = true; break;
            }
        }
        if (modified) {
            accounts.push_back(make_pair(username, password));
        }
    }
    if (accounts.size() == 0) {
        if (n == 1) {
            cout << "There is 1 account and no account is modified" << endl;
        } else {
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
    } else {
       cout << accounts.size() << endl;
       for (int i = 0;  i < accounts.size(); ++i) {
           cout << accounts[i].first << " " << accounts[i].second << endl;
       }
    }
    return 0;
}
