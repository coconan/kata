// 2013-12-7
// xuetangX.com 数据结构 PA2-2

#include <iostream>

using namespace std;

int in[5005], post[5005], pre[5005], k;

int find(int * arr, int n, int t) {
	for (int i = 0; i < n; i++) {
	    if (arr[i] == t) return i;
	}
	return -1;
}

void rebuild(int * in, int * post, int n) {
	if (n == 0) return;
	else {
		int p = find(in, n, post[n-1]);
		if (p == -1) return;
		pre[k++] = in[p];
		rebuild(in, post, p);
		rebuild(in+p+1, post+p, n-p-1);
	}
}

int main() {
	int n;
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> post[i];
	}

	k = 0;
	rebuild(in, post, n);
	
	if (k < n) cout << -1 << endl;
	else {
		cout << pre[0];
		for (int i = 1; i < n; i++) {
			cout << " " << pre[i];
		}
		cout << endl;
	}
	return 0;
}