#include <stdio.h>

struct TreeNode {
	int value;
	int left, right;
	TreeNode(int v=1, int l=-1, int r=-1): value(v), left(l), right(r) {}
};

struct Tree {
	TreeNode *allNodes;
	int size;
};

Tree allProperTree[4000000];
int counter = 2, lastLevelLo=2, lastLevelHi=3;

void mergeTree(Tree &nextTree, const Tree &left, const Tree &right) {
	nextTree.size = left.size + right.size + 1;
	nextTree.allNodes = new TreeNode[nextTree.size+1];
	
	int leftIndex = 2, rightIndex = left.size + 2;
	int leftOffset = 1, rightOffset = left.size + 1;
	nextTree.allNodes[1].left = leftIndex;
	nextTree.allNodes[1].right = rightIndex;
	
	for (int i = 1; i <= left.size; i++) {
		nextTree.allNodes[leftOffset+i].value = left.allNodes[i].value + leftOffset;
		if (left.allNodes[i].left > 0 && left.allNodes[i].right > 0) {
			nextTree.allNodes[leftOffset+i].left = left.allNodes[i].left + leftOffset;
			nextTree.allNodes[leftOffset+i].right = left.allNodes[i].right + leftOffset;
		}
	}

	for (int i = 1; i <= right.size; i++) {
		nextTree.allNodes[rightOffset+i].value = right.allNodes[i].value + rightOffset;
		if (right.allNodes[i].left > 0 && right.allNodes[i].right > 0) {
			nextTree.allNodes[rightOffset+i].left = right.allNodes[i].left + rightOffset;
			nextTree.allNodes[rightOffset+i].right = right.allNodes[i].right + rightOffset;
		}
	}
}

void createProperTree(int maxLevel) {
	int level = 2;
	while (level < maxLevel) {
		for (int i = 1; i < lastLevelLo; i++) {
			for (int j = lastLevelLo; j < lastLevelHi; j++) {
				Tree &nextTree = allProperTree[++counter];
				Tree &left = allProperTree[i];
				Tree &right = allProperTree[j];
				mergeTree(nextTree, left, right);
			}
		}

		for (int i = lastLevelLo; i < lastLevelHi; i++) {
			for (int j = 1; j < lastLevelLo; j++) {
				Tree &nextTree = allProperTree[++counter];
				Tree &left = allProperTree[i];
				Tree &right = allProperTree[j];
				mergeTree(nextTree, left, right);
			}
		}

		for (int i = lastLevelLo; i < lastLevelHi; i++) {
			for (int j = lastLevelLo; j < lastLevelHi; j++) {
				Tree &nextTree = allProperTree[++counter];
				Tree &left = allProperTree[i];
				Tree &right = allProperTree[j];
				mergeTree(nextTree, left, right);
			}
		}
		level++;
		lastLevelLo = lastLevelHi;
		lastLevelHi = counter + 1;
	}
}

void preOrderTraverse(TreeNode &root, Tree &tree) {
	if (root.left == -1 && root.right == -1) {
		//printf("value=%d left=%d right=%d\n", root.value, root.left, root.right);
		printf("%d ", root.value);
		return;
	}
	TreeNode &leftChild = tree.allNodes[root.left];
	TreeNode &rightChild = tree.allNodes[root.right];
	//printf("root=%d left=%d right=%d\n", root.value, root.left, root.right);
	printf("%d ", root.value);
	preOrderTraverse(leftChild, tree);
	preOrderTraverse(rightChild, tree);
}


void inOrderTraverse(TreeNode &root, Tree &tree) {
	if (root.left == -1 && root.right == -1) {
		//printf("value=%d left=%d right=%d\n", root.value, root.left, root.right);
		printf("%d ", root.value);
		return;
	}
	TreeNode &leftChild = tree.allNodes[root.left];
	TreeNode &rightChild = tree.allNodes[root.right];
	inOrderTraverse(leftChild, tree);
	//printf("root=%d left=%d right=%d\n", root.value, root.left, root.right);
	printf("%d ", root.value);
	inOrderTraverse(rightChild, tree);
}

void postOrderTraverse(TreeNode &root, Tree &tree) {
	if (root.left == -1 && root.right == -1) {
		//printf("value=%d left=%d right=%d\n", root.value, root.left, root.right);
		printf("%d ", root.value);
		return;
	}
	TreeNode &leftChild = tree.allNodes[root.left];
	TreeNode &rightChild = tree.allNodes[root.right];
	postOrderTraverse(leftChild, tree);
	postOrderTraverse(rightChild, tree);
	printf("%d ", root.value);
}


void freeAllTree() {
	for (int i = 1; i <= counter; i++) {
		delete [] allProperTree[i].allNodes;
	}
}

int main() {
	
	
	TreeNode *oneLevelTree = new TreeNode[2];
	TreeNode *twoLevelTree = new TreeNode[4];
	twoLevelTree[1].left = 2;
	twoLevelTree[1].right = 3;
	twoLevelTree[2].value = 2;
	twoLevelTree[3].value = 3;
	allProperTree[1].allNodes = oneLevelTree;
	allProperTree[1].size = 1;
	allProperTree[2].allNodes = twoLevelTree;
	allProperTree[2].size = 3;
	createProperTree(6);
	freopen("in.txt", "w", stdout);
	for (int i = 1; i <= counter; i++) {
		printf("%d\n", allProperTree[i].size);
		preOrderTraverse(allProperTree[i].allNodes[1], allProperTree[i]);
		printf("\n");
		postOrderTraverse(allProperTree[i].allNodes[1], allProperTree[i]);
		printf("\n");
	}

	freopen("out.txt", "w", stdout);
	for (int i = 1; i <= counter; i++) {
		printf("%d\n", allProperTree[i].size);
		inOrderTraverse(allProperTree[i].allNodes[1], allProperTree[i]);
		printf("\n");
	}
	freopen("test.txt", "w", stdout);
	printf("counter=%d\n", counter);

	freeAllTree();
	return 0;
}