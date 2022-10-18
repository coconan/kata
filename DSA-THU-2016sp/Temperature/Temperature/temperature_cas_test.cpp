// 2016-05-25 11:51用fractional cascading来进行优化
// 2016-05-25 17:50已将fractional cascading加入程序中，并通过了OJ的测试，接下来
// 要用cascading替换二分搜索，将时间复杂度降低O(lgn)
#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

enum Child { ROOT, LEFT, RIGHT };
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
	int *yOrder, *left, *right;
	long long *preSum;
	AssocVector() : n(0), yOrder(NULL), preSum(NULL), left(NULL), right(NULL) {}
};

struct TreeNode {
	int x;
	TreeNode *lChild, *rChild;
	AssocVector *assocVector;
};

Station stations[50005];
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

void buildassocVector(AssocVector *childassoc, AssocVector *parentassoc, Child child, int lo, int hi) {
	childassoc->n = hi - lo;
	childassoc->yOrder = new int[hi - lo];
	childassoc->preSum = new long long[hi - lo];
	for (int i = 0; i < hi - lo; i++) {
		childassoc->yOrder[i] = xOrder[lo + i];
	}
	sort(childassoc->yOrder, 0, hi - lo, ylt);
	long long total = 0;
	for (int i = 0; i < hi - lo; i++) {
		total += stations[childassoc->yOrder[i]].temp;
		childassoc->preSum[i] = total;
	}
	int *cascade;
	if (child == LEFT) {
		parentassoc->left = new int[parentassoc->n];
		cascade = parentassoc->left;
	} else {
		parentassoc->right = new int[parentassoc->n];
		cascade = parentassoc->right;
	}
	for (int pi = 0, ci = 0, n = parentassoc->n; pi < n; pi++) {
		// lowerboud, upperbound invariant
		int cy = stations[childassoc->yOrder[ci]].y;
		int	py = stations[parentassoc->yOrder[pi]].y;
		if (cy <= py) {
			cascade[pi] = ci;
			if (ci < (childassoc->n - 1)) {
				ci++;
			}
		} else {
			if (ci > 0) {
				cascade[pi] = ci - 1;
			} else {
				cascade[pi] = ci;
			}
		}

	}
}

TreeNode *buildRangeTree(TreeNode *parent, Child child, int lo, int hi) {
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
		if (parent != NULL) {
			buildassocVector(assocVector, parent->assocVector, child, lo, hi);
		}
		return leaf;
	}
	int mi = lo + (hi - lo + 1) / 2;
	AssocVector *assocVector = new AssocVector;
	if (parent != NULL) {
		buildassocVector(assocVector, parent->assocVector, child, lo, hi);
	} else {
		assocVector->n = hi - lo;
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
	TreeNode *node = new TreeNode;
	node->x = stations[xOrder[mi - 1]].x;
	node->assocVector = assocVector;
	node->lChild = buildRangeTree(node, LEFT, lo, mi);
	node->rChild = buildRangeTree(node, RIGHT, mi, hi);
	return node;
}

void assocVectorPrint(AssocVector *assoc) {
	printf("assoc: ");
	for (int i = 0; i < assoc->n; i++) {
		printf("y=%d t=%d  ", stations[assoc->yOrder[i]].y, stations[assoc->yOrder[i]].temp);
	}
	if (assoc->left == NULL) {
		return;
	}
	printf("\n\tleft: ");
	for (int i = 0; i < assoc->n; i++) {
		printf("%d ", assoc->left[i]);
	}
	printf("\n\tright: ");
	for (int i = 0; i < assoc->n; i++) {
		printf("%d ", assoc->right[i]);
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
	}
	return lo;
}

long long report(TreeNode *root, int y1, int y2, int *counter, int lower, int upper) {
	AssocVector *assoc = root->assocVector;
	int lo = lowerbound(assoc->yOrder, 0, assoc->n, y1);
	int hi = upperbound(assoc->yOrder, 0, assoc->n, y2);
	//printf("lo=%d, lower=%d\n", lo, lower);
	//printf("hi=%d, upper=%d\n", hi, upper);
	*counter += hi - lo;
	if (hi <= lo) return 0;
	return assoc->preSum[hi - 1] - assoc->preSum[lo] + stations[assoc->yOrder[lo]].temp;
}

long long rangeQuery(TreeNode *root, int x1, int y1, int x2, int y2, int lower, int upper) {
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

	int *leftcascade = root->assocVector->left;
	int *rightcascade = root->assocVector->right;
	if (x2 < root->x) { // 2014年的程序多了一个'='，造成不能统计坐标相同的点
		return rangeQuery(root->lChild, x1, y1, x2, y2, leftcascade[lower], leftcascade[upper]);
	} else if (x1 > root->x) {
		return rangeQuery(root->rChild, x1, y1, x2, y2, rightcascade[lower], rightcascade[upper]);
	}
	else {
		TreeNode *lnext = root->lChild, *rnext = root->rChild;
		long long sum = 0;
		int counter = 0;
		{
			int *leftc = leftcascade;
			int *rightc = rightcascade;
			int lo = leftc[lower];
			int hi = leftc[upper];
			while (lnext->lChild && lnext->rChild) {
				leftc = lnext->assocVector->left;
				rightc = lnext->assocVector->right;
				if (lnext->x >= x1) {
					sum += report(lnext->rChild, y1, y2, &counter, rightc[lo], rightc[hi]);
					lo = leftc[lo];
					hi = leftc[hi];
					lnext = lnext->lChild;
				}
				else {
					lo = rightc[lo];
					hi = rightc[hi];
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
		}
		{
			int *leftc = leftcascade;
			int *rightc = rightcascade;
			int lo = leftc[lower];
			int hi = rightc[upper];
			while (rnext->lChild && rnext->rChild) {
				leftc = rnext->assocVector->left;
				rightc = rnext->assocVector->right;
				if (rnext->x <= x2) {
					sum += report(rnext->lChild, y1, y2, &counter, leftc[lo], leftc[hi]);
					lo = rightc[lo];
					hi = rightc[hi];
					rnext = rnext->rChild;
				}
				else {
					lo = leftc[lo];
					hi = leftc[hi];
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
		}
		if (counter == 0) return 0;
		return sum / counter;
	}
}

int main() {
	srand(42);
	int n = GetNumOfStation();
	for (int i = 0; i < n; i++) {
		GetStationInfo(i, &stations[i].x, &stations[i].y, &stations[i].temp);
		xOrder[i] = i;
	}
	sort(xOrder, 0, n, xlt);
	TreeNode *root = buildRangeTree(NULL, ROOT, 0, n);
	//treeTraverse(root, 0);
	while (true) {
		int x1, x2, y1, y2;
		int code = GetQuery(&x1, &y1, &x2, &y2);
		if (code == 0) break;
		AssocVector *assoc = root->assocVector;
		int lower = lowerbound(assoc->yOrder, 0, assoc->n, y1);
		int upper = upperbound(assoc->yOrder, 0, assoc->n, y2);
		long long temp = rangeQuery(root, x1, y1, x2, y2, lower, upper-1);
		Response(temp);
	}
	//treeTraverse(root, 0);
}
