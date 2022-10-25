#include <iostream>
#include <string>
#include <vector>

using namespace std;

string digitWords[10] = {"zero", "one", "two", "three", "four",
                         "five", "six", "seven", "eight", "nine"};

int main() {
    string digits;
    int digitsSum = 0;
    cin >> digits;
    for (int i = 0; i < digits.length(); ++i) {
        digitsSum += (int)digits[i] - '0';
    }
    vector<string> output;
    do {
        output.push_back( digitWords[ digitsSum % 10 ] );
        digitsSum /= 10;
    } while (digitsSum);
    for (int i = output.size() - 1; i > 0; --i) {
        cout << output[i] << " ";
    }
    cout << output[0] << endl;
    return 0;
}
