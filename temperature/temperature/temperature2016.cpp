// 2016-05-24 19:17开始debug，21:42修复了bug，接下来进行优化
// 2016-05-25 将station进行了合并，性能并没有明显提高
#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

struct Station {
	int x, y, temp, n;
	Station() : x(0), y(0), temp(0), n(1) {}
	Station(const Station &other) {
		x = other.x;
		y = other.y;
		temp = other.temp;
	}
};

struct AssocVector {
	int n;
	int *index;
	long long *preSum;
	int *counts;
	AssocVector() : n(0), index(NULL), preSum(NULL), counts(NULL) {}
};

struct TreeNode {
	int x;
	TreeNode *lChild, *rChild;
	AssocVector *assocVector;
};

Station *stations = new Station[50005];
Station *scopy = new Station[50005];
int xOrder[50005];

bool xlt(int i, int j) {
	if (stations[i].x != stations[j].x) {
		return stations[i].x <= stations[j].x;
	}
	return stations[i].y <= stations[j].y;
}

bool ylt(int i, int j) {
	return stations[i].y <= stations[j].y;
}

int partition(int *index, int lo, int hi, bool(*lt)(int, int)) {
	int randidx = rand() % (hi - lo + 1) + lo;
	int pivot = index[randidx];
	index[randidx] = index[lo];
	while (lo < hi) {
		while (lt(pivot, index[hi]) && lo < hi) hi--;
		index[lo] = index[hi];
		while (lt(index[lo], pivot) && lo < hi) lo++;
		index[hi] = index[lo];
	}
	index[lo] = pivot;
	return lo;
}

void sort(int *index, int lo, int hi, bool(*lt)(int, int)) {
	if (hi - lo < 2) return;
	int mi = partition(index, lo, hi - 1, lt);
	sort(index, lo, mi, lt);
	sort(index, mi + 1, hi, lt);
}

int merge(int n) {
	int c = 0;
	scopy[c].x = stations[xOrder[0]].x;
	scopy[c].y = stations[xOrder[0]].y;
	scopy[c].temp = stations[xOrder[0]].temp;
	scopy[c].n = stations[xOrder[0]].n;
	for (int i = 1; i < n; i++) {
		if (stations[xOrder[i]].x == scopy[c].x && stations[xOrder[i]].y == scopy[c].y) {
			scopy[c].temp += stations[xOrder[i]].temp;
			scopy[c].n++;
		} else {
			c++;
			scopy[c].x = stations[xOrder[i]].x;
			scopy[c].y = stations[xOrder[i]].y;
			scopy[c].temp = stations[xOrder[i]].temp;
			scopy[c].n = stations[xOrder[i]].n;
		}
	}
	return c + 1;
}

void assocVectorCopy(AssocVector *assocVector, int lo, int hi) {
	assocVector->n = hi - lo;
	int *index = new int[hi - lo];
	assocVector->index = new int[hi - lo];
	assocVector->preSum = new long long[hi - lo];
	assocVector->counts = new int[hi - lo];
	for (int i = 0; i < hi - lo; i++) {
		assocVector->index[i] = xOrder[lo + i];
	}
	sort(assocVector->index, 0, hi - lo, ylt);
	long long total = 0, count = 0;
	for (int i = 0; i < hi - lo; i++) {
		total += stations[assocVector->index[i]].temp;
		assocVector->preSum[i] = total;
		count += stations[assocVector->index[i]].n;
		assocVector->counts[i] = count;
	}
}

TreeNode * buildRangeTree(int lo, int hi) {
	if (hi - lo == 1) {
		AssocVector *assocVector = new AssocVector;
		assocVector->n = 1;
		assocVector->index = new int(xOrder[lo]);
		assocVector->preSum = new long long(stations[xOrder[lo]].temp);
		assocVector->counts = new int(stations[xOrder[lo]].n);
		TreeNode *leaf = new TreeNode;
		leaf->lChild = NULL;
		leaf->rChild = NULL;
		leaf->x = stations[xOrder[lo]].x;
		leaf->assocVector = assocVector;
		return leaf;
	}
	int mi = lo + (hi - lo + 1) / 2;
	AssocVector *assocVector = new AssocVector;
	assocVectorCopy(assocVector, lo, hi);
	TreeNode *node = new TreeNode;
	node->x = stations[xOrder[mi - 1]].x;
	node->assocVector = assocVector;
	node->lChild = buildRangeTree(lo, mi);
	node->rChild = buildRangeTree(mi, hi);
	return node;
}

void assocVectorPrint(AssocVector *assoc) {
	printf("assoc: ");
	for (int i = 0; i < assoc->n; i++) {
		printf("y=%d t=%d  ", stations[assoc->index[i]].y, stations[assoc->index[i]].temp);
	}
}

void treeTraverse(TreeNode *root, int n) {
	if (root == NULL) return;
	treeTraverse(root->lChild, n + 1);
	printf("%d ", root->x);
	assocVectorPrint(root->assocVector);
	printf("\n");
	treeTraverse(root->rChild, n + 1);
}

int upperbound(int *index, int lo, int hi, int y) {
	while (lo < hi) {
		int mi = (hi - lo) / 2 + lo;
		if (y < stations[index[mi]].y) {
			hi = mi;
		} else {
			lo = mi + 1;
		}
	}
	return lo;
}

int lowerbound(int *index, int lo, int hi, int y) {
	while (lo < hi) {
		int mi = (hi - lo) / 2 + lo;
		if (y > stations[index[mi]].y) {
			lo = mi + 1;
		} else {
			hi = mi;
		}
	}
	return lo;
}

long long report(TreeNode *root, int y1, int y2, int *counter) {
	AssocVector *assoc = root->assocVector;
	int lo = lowerbound(assoc->index, 0, assoc->n, y1);
	int hi = upperbound(assoc->index, 0, assoc->n, y2);
	//*counter += hi - lo;
	if (hi <= lo) return 0;
	*counter += assoc->counts[hi - 1] - assoc->counts[lo] + stations[assoc->index[lo]].n;
	return assoc->preSum[hi - 1] - assoc->preSum[lo] + stations[assoc->index[lo]].temp;
}

long long rangeQuery(TreeNode *root, int x1, int y1, int x2, int y2) {
	if (root->lChild == NULL && root->rChild == NULL) {
		int x = root->x;
		if (x1 <= x && x <= x2) {
			AssocVector *assoc = root->assocVector;
			int y = stations[assoc->index[0]].y;
			if (y1 <= y && y <= y2) {
				return stations[assoc->index[0]].temp;
			}
			return 0;
		}
		return 0;
	}
	if (x2 < root->x) { // 2014年的程序多了一个'='，造成不能统计坐标相同的点
		return rangeQuery(root->lChild, x1, y1, x2, y2);
	}
	else if (x1 > root->x) {
		return rangeQuery(root->rChild, x1, y1, x2, y2);
	}
	else {
		TreeNode *lnext = root->lChild, *rnext = root->rChild;
		long long sum = 0;
		int counter = 0;
		while (lnext->lChild && lnext->rChild) {
			if (lnext->x >= x1) {
				sum += report(lnext->rChild, y1, y2, &counter);
				lnext = lnext->lChild;
			}
			else {
				lnext = lnext->rChild;
			}
		}
		if (lnext->x >= x1) {
			AssocVector *assoc = lnext->assocVector;
			int y = stations[assoc->index[0]].y;
			if (y1 <= y && y <= y2) {
				sum += assoc->preSum[0];
				counter += assoc->counts[0];
			}
		}
		while (rnext->lChild && rnext->rChild) {
			if (rnext->x <= x2) {
				sum += report(rnext->lChild, y1, y2, &counter);
				rnext = rnext->rChild;
			}
			else {
				rnext = rnext->lChild;
			}
		}
		if (rnext->x <= x2) {
			AssocVector *assoc = rnext->assocVector;
			int y = stations[assoc->index[0]].y;
			if (y1 <= y && y <= y2) {
				sum += assoc->preSum[0];
				counter += assoc->counts[0];
			}
		}
		if (counter == 0) return 0;
		return sum / counter;
	}
}

int main() {
	int n = GetNumOfStation();
	for (int i = 0; i < n; i++) {
		GetStationInfo(i, &stations[i].x, &stations[i].y, &stations[i].temp);
		xOrder[i] = i;
	}
	sort(xOrder, 0, n, xlt);
	n = merge(n);
	stations = scopy;
	for (int i = 0; i < n; i++) {
		xOrder[i] = i;
	}
	TreeNode *root = buildRangeTree(0, n);
	int bound = 1000000, i = 0;
	while (true) {
		int x1, x2, y1, y2;
		int code = GetQuery(&x1, &y1, &x2, &y2);
		if (code == 0) break;
		long long temp;
		if (i++ <= bound) {
			temp = rangeQuery(root, x1, y1, x2, y2);
		} else {
			temp = 0;
		}
		Response(temp);
	}
	//treeTraverse(root, 0);
}