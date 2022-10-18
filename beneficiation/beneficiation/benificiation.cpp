#include <stdio.h>
#include <stdlib.h>
#include "beneficiation.h"

int indice[10000];
int low[10000], high[10000];

//void getMidFirst(int lo, int hi) {
//	int mi = (hi + lo) / 2 - 1;
//	int a = indice[lo],  b = indice[mi], c = indice[hi-1];
//	int wa, wb, wc, wd;
//	Measure(a, b, c, -1, &wa, &wb, &wc, &wd);
//	if (wb == 0) {
//		indice[lo] = b;
//		indice[mi] = a;
//	}
//	if (wc == 0) {
//		indice[lo] = c;
//		indice[hi-1] = a;
//	}
//}

void getMidFirst(int lo, int hi) {
	int i1 = rand() % (hi - lo) + lo, i2 = rand() % (hi - lo) + lo, i3 = rand() % (hi - lo) + lo;
	int a = indice[i1],  b = indice[i2], c = indice[i3], tmp = indice[lo];
	int wa, wb, wc, wd;
	Measure(a, b, c, -1, &wa, &wb, &wc, &wd);
	if (wa == 0) {
		indice[lo] = a;
		indice[i1] = tmp;
	}
	if (wb == 0) {
		indice[lo] = b;
		indice[i2] = tmp;
	}
	if (wc == 0) {
		indice[lo] = c;
		indice[i3] = tmp;
	}
}

int partition(int lo, int hi) {
	if (hi - lo > 16) {
		getMidFirst(lo, hi);
	} else {
		int tmp = indice[lo], index = rand() % (hi - lo) + lo;
		indice[lo] = indice[index];
		indice[index] = tmp;
	}
	int pivot = indice[lo], l = 0, h = 0;
	int last = -1, step = 3, i;
	for (i = lo+1; i + step <= hi; ) {
		int a = pivot, b = indice[i++], c = indice[i++], d;
		if (last != -1) {
			d = last;
		} else {
			d = indice[i++];
		}
		int wa, wb, wc, wd;
		Measure(a, b, c, d, &wa, &wb, &wc, &wd);
		if (wa == 0) {
			wb == 0 ? last = b : (wb == -1 ? low[l++] = b : high[h++] = b);
			wc == 0 ? last = c : (wc == -1 ? low[l++] = c : high[h++] = c);
			wd == 0 ? last = d : (wd == -1 ? low[l++] = d : high[h++] = d);
			step = 2;
		} else if (wa == 1) {
			low[l++] = b;
			low[l++] = c;
			low[l++] = d;
			last = -1;
			step = 3;
		} else {
			high[h++] = b;
			high[h++] = c;
			high[h++] = d;
			last = -1;
			step = 3;
		}
	}
	if ((i == hi && last != -1) || (hi - i == 1 && last == -1)) {
		int a = pivot;
		int b = last == -1 ? indice[i] : last;
		int wa, wb, wc, wd;
		Measure(a, b, -1, -1, &wa, &wb, &wc, &wd);
		wb == -1 ? low[l++] = b : high[h++] = b;
	}
	if ((hi - i == 1 && last != -1) || (hi - i == 2 && last == -1)) {
		int a = pivot, b = indice[i++];
		int c = last == -1 ? indice[i] : last;
		int wa, wb, wc, wd;
		Measure(a, b, c, -1, &wa, &wb, &wc, &wd);
		if (wa == -1) {
			high[h++] = b;
			high[h++] = c;
		} else if (wa == 1) {
			low[l++] = b;
			low[l++] = c;
		} else {
			wb == -1 ? low[l++] = b : high[h++] = b;
			wc == -1 ? low[l++] = c : high[h++] = c;
		}
	}
	for (i = 0; i < h; i++) {
		indice[lo+i] = high[i];
	}
	indice[lo+h] = pivot;
	for (i = 0; i < l; i++) {
		indice[lo+h+i+1] = low[i];
	}
	return h + lo;
}

void qsort(int lo, int hi) {
	if (hi - lo <= 1) return;
	if (hi - lo == 2) {
		int a = indice[lo], b = indice[lo+1];
		int wa, wb, wc, wd;
		Measure(a, b, -1, -1, &wa, &wb, &wc, &wd);
		if (wa < wb) {
			indice[lo] = b;
			indice[lo+1] = a;
		}
		return;
	}
	if (hi - lo == 3) {
		int a = indice[lo], b = indice[lo+1], c = indice[lo+2];
		int wa, wb, wc, wd;
		Measure(a, b, c, -1, &wa, &wb, &wc, &wd);
		wa == 1 ? indice[lo] = a : (wa == 0 ? indice[lo+1] = a : indice[lo+2] = a);
		wb == 1 ? indice[lo] = b : (wb == 0 ? indice[lo+1] = b : indice[lo+2] = b);
		wc == 1 ? indice[lo] = c : (wc == 0 ? indice[lo+1] = c : indice[lo+2] = c);
		return;
	}
	if (hi - lo == 4) {
		int a = indice[lo], b = indice[lo+1], c = indice[lo+2], d = indice[lo+3];
		int wa, wb, wc, wd, ab[2], i = 0;
		Measure(a, b, c, d, &wa, &wb, &wc, &wd);
		wa == 1 ? indice[lo] = a : (wa == -1 ? indice[lo+3] = a : ab[i++] = a);
		wb == 1 ? indice[lo] = b : (wb == -1 ? indice[lo+3] = b : ab[i++] = b);
		wc == 1 ? indice[lo] = c : (wc == -1 ? indice[lo+3] = c : ab[i++] = c);
		wd == 1 ? indice[lo] = d : (wd == -1 ? indice[lo+3] = d : ab[i++] = d);
		Measure(ab[0], ab[1], -1, -1, &wa, &wb, &wc, &wd);
		wa == 1 ? indice[lo+1] = ab[0] : indice[lo+2] = ab[0];
		wb == 1 ? indice[lo+1] = ab[1] : indice[lo+2] = ab[1];
		return;
	}
	int mi = partition(lo, hi);
	qsort(lo, mi);
	qsort(mi+1, hi);
}

int main() {
	int n;
	while (n = GetNumOfOre()) {
		for (int i = 0; i < n; i++) {
			indice[i] = i;
		}
		qsort(0, n);
		for (int i = 0; i < n; i++) {
			Report(indice[i], i);
		}
	}
	return 0;
}