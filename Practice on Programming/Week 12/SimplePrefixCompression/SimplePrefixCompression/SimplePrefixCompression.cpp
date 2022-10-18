#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPrefix(string& s1, string& s2) {
	int len1 = s1.length(), len2 = s2.length();
	int numPrefix = 0;
	while (numPrefix < len1 && numPrefix < len2 && 
		   s1[numPrefix] == s2[numPrefix]) {
		numPrefix++;
	}
	return numPrefix;
}

int main() {
	vector<string> strings;
	string s;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		strings.push_back(s);
	}

	int total = 0;
	for (int i = strings.size()-1; i > 0; i--) {
		int numPrefix = countPrefix(strings[i], strings[i-1]);
		total += strings[i].length() - numPrefix + 1;
	}
	total += strings[0].length();

	cout << total << endl;
}