#include <iostream>

using namespace std;

int main() {
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                   '8', '9', 'A', 'B', 'C'};
    int red, green, blue;
    cin >> red >> green >> blue;
    string output("#");
    output.push_back(digits[red/13]);
    output.push_back(digits[red%13]);
    output.push_back(digits[green/13]);
    output.push_back(digits[green%13]);
    output.push_back(digits[blue/13]);
    output.push_back(digits[blue%13]);
    cout << output << endl;
    return 0;
}
