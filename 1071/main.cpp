#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;
//string words[10000];
int nword;
int gap = 'A' - 'a';
map<string, int> wordst;

bool isAlpha(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char tolowerchar(char c) {
    if ('A'<= c && c <='Z') {
        return c - gap;
    }
    return c;
}

int main() {
    fstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    string input;
    getline(cin, input);
    int maxw = -1;
    string maxword("");
    string word("");
    int s, e;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (int i = 0; i < input.size();) {
        while (!isAlpha(input[i]) && i < input.length())
            ++ i;
        if (i == input.size())
          break;
        s = i;

        while (isAlpha(input[i]) && i < input.length())
            ++ i;
        e = i;
        word = input.substr(s, e-s);
        if (wordst.count(word) != 0) {
            wordst[word] += 1;
        } else {
            wordst[word] = 1;
        }
        if (wordst[word] > maxw) {
            maxword = word;
            maxw = wordst[word];
        } else if (wordst[word] == maxw && maxword > word) {
            maxword = word;
        }
        word = "";
    }
    cout << maxword << " " << maxw << endl;
    return 0;
}
