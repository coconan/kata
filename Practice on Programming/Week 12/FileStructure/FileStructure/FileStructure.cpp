#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Dir {
	string name;
	vector<Dir*> subDirs;
	vector<string> files;
	Dir(const string& _name): name(_name) {}
};

Dir* constructDir(const string& name) {
	Dir* d = new Dir(name);
	string data;
	while(true) {
		cin >> data;
		if (data[0] == 'd') {
			d->subDirs.push_back(constructDir(data));
		} else if (data[0] == 'f') {
			d->files.push_back(data);
		} else {
			break;
		}
	}
	if (data == "#") {
		d->name = "NULL";
	}
	return d;
}

void printDir(Dir* d, int level) {
	for (int i = 0; i < level; i++) {
		cout << "|     ";
	}
	cout << d->name << endl;

	for (int i = 0; i < d->subDirs.size(); i++) {
		printDir(d->subDirs[i], level+1);
	}

	sort(d->files.begin(), d->files.end());
	for (int i = 0; i < d->files.size(); i++) {
		for (int j = 0; j < level; j++) {
			cout << "|     ";
		}
		cout << d->files[i] << endl;
	}
}

void freeDir(Dir* d) {
	for (int i = 0; i < d->subDirs.size(); i++) {
		freeDir(d->subDirs[i]);
	}
	free(d);
}

int main() {
	int counter = 0;
	while (true) {
		counter++;
		Dir* d = constructDir("ROOT");
		if (d->name != "NULL") {
			if (counter > 1) {
				cout << endl;
			}
			cout << "DATA SET " << counter << ":" << endl;
			printDir(d, 0);
			freeDir(d);
		} else {
			freeDir(d);
			break;
		}
	}
	return 0;
}