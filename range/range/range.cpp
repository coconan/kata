#include <iostream>
#include <cstdio>

using namespace std;

int arr[500005];
int aux[500005];

void merge(int lo, int mi, int hi) {
	for (int i = lo; i < hi; i++) {
		aux[i] = arr[i];
	}
	
	int l = lo, r = mi, i = lo;
	while (l < mi && r < hi) {
		if (aux[l] < aux[r]) {
			arr[i] = aux[l];
			l++;
		} else {
			arr[i] = aux[r];
			r++;
		}
		i++;
	}
	
	while (l < mi) {
		arr[i] = aux[l];
		i++; l++;
	}

	while (r < hi) {
		arr[i] = aux[r];
		i++; r++;
	}
}

void mergeSort(int lo, int hi) {
	if (hi - lo <= 1) return;
	int mi = (lo + hi) / 2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

int search(int e, bool lowest, int n) {
	int lo = 0, hi =n;

	while (lo < hi) {
		int mi = (lo + hi) / 2;
		if (lowest) {
			if (arr[mi] < e) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		} else {
			if (arr[mi] > e) {
				hi = mi;
			} else {
				lo = mi + 1;
			}
		}
	}
	
	return hi;
}

int main() {
	int m, n;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}

	mergeSort(0, n);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ai = search(a, true, n);
		int bi = search(b, false, n);
		printf("%d\n", bi-ai);
	}

	return 0;
}