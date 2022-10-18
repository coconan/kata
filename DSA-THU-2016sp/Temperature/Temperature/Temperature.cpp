// 2016-05-24 19:17开始debug，21:42修复了bug，接下来进行优化
#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"
/*

struct Station {
	int x, y, temp;
	Station() : x(0), y(0), temp(0) {}
	Station(const Station &other) {
		x = other.x;
		y = other.y;
		temp = other.temp;
	}
};

struct AssocVector {
	int n;
	int *yOrder;
	long long *preSum;
	AssocVector() : n(0), yOrder(NULL), preSum(NULL) {}
};

struct TreeNode {
	int x;
	TreeNode *lChild, *rChild;
	AssocVector *assocVector;
};

Station stations[50005];
int xOrder[50005];

bool xlt(int i, int j) {
	return stations[i].x <= stations[j].x;
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

void assocVectorCopy(AssocVector *assocVector, int lo, int hi) {
	assocVector->n = hi - lo;
	int *index = new int[hi - lo];
	assocVector->yOrder = new int[hi - lo];
	assocVector->preSum = new long long[hi - lo];
	for (int i = 0; i < hi - lo; i++) {
		assocVector->yOrder[i] = xOrder[lo + i];
	}
	sort(assocVector->yOrder, 0, hi - lo, ylt);
	long long total = 0;
	for (int i = 0; i < hi - lo; i++) {
		total += stations[assocVector->yOrder[i]].temp;
		assocVector->preSum[i] = total;
	}
}

TreeNode * buildRangeTree(int lo, int hi) {
	if (hi - lo == 1) {
		AssocVector *assocVector = new AssocVector;
		assocVector->n = 1;
		assocVector->yOrder = new int(xOrder[lo]);
		assocVector->preSum = new long long(stations[xOrder[lo]].temp);
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
		printf("y=%d t=%d  ", stations[assoc->yOrder[i]].y, stations[assoc->yOrder[i]].temp);
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
		int mi = (lo + hi) >> 1;
		if (y < stations[index[mi]].y) {
			hi = mi;
		}
		else {
			lo = mi + 1;
		}
		//lo = mi + 1;
	}
	return lo;
}

int lowerbound(int *index, int lo, int hi, int y) {
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (y > stations[index[mi]].y) {
			lo = mi + 1;
		}
		else {
			hi = mi;
		}
		//lo = mi + 1;
	}
	return lo;
}

long long report(TreeNode *root, int y1, int y2, int *counter) {
	AssocVector *assoc = root->assocVector;
	int lo = lowerbound(assoc->yOrder, 0, assoc->n, y1); //bisect(assoc->index, 0, assoc->n, y1, true);
	int hi = upperbound(assoc->yOrder, 0, assoc->n, y2); //bisect(assoc->index, 0, assoc->n, y2, false);
	*counter += hi - lo;
	if (hi <= lo) return 0;
	return assoc->preSum[hi - 1] - assoc->preSum[lo] + stations[assoc->yOrder[lo]].temp;
}

long long rangeQuery(TreeNode *root, int x1, int y1, int x2, int y2) {
	if (root->lChild == NULL && root->rChild == NULL) {
		int x = root->x;
		if (x1 <= x && x <= x2) {
			AssocVector *assoc = root->assocVector;
			int y = stations[assoc->yOrder[0]].y;
			if (y1 <= y && y <= y2) {
				return stations[assoc->yOrder[0]].temp;
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
			int y = stations[assoc->yOrder[0]].y;
			if (y1 <= y && y <= y2) {
				sum += assoc->preSum[0];
				counter++;
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
			int y = stations[assoc->yOrder[0]].y;
			if (y1 <= y && y <= y2) {
				sum += assoc->preSum[0];
				counter++;
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
	TreeNode *root = buildRangeTree(0, n);
	//treeTraverse(root, 0);
	while (true) {
		int x1, x2, y1, y2;
		int code = GetQuery(&x1, &y1, &x2, &y2);
		if (code == 0) break;
		long long temp = rangeQuery(root, x1, y1, x2, y2);
		Response(temp);
	}
	//treeTraverse(root, 0);
}
*/