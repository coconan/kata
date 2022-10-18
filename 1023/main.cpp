#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

string doubleNum(string num) {
      int carry = 0;
      string doubled;
      for (int i = num.size()-1; i >= 0; --i) {
          int d = (num[i]-'0') * 2 + carry;
          doubled.insert(0, 1, d % 10 + '0');
          carry = d / 10;
      }
      if (carry != 0) {
          doubled.insert(0, 1, carry + '0');
      }
      return doubled;
}

int main(){
    string num;
    cin >> num;
    string doubleN = doubleNum(num);
    string numCopy(num), doubleNCopy(doubleN);
    sort(numCopy.begin(), numCopy.end());
    sort(doubleNCopy.begin(), doubleNCopy.end());
    if (numCopy == doubleNCopy) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << doubleN << endl;
    return 0;
}
