#include <stdio.h>
#include <memory.h>

#define CAPACITY 1000

struct Stack {
	unsigned elem[1000], size;
};

struct Queue {
	unsigned elem[1000], size;
	unsigned front, rear;
};

Stack stacks[2000];
Queue frontQ, maxQ;
unsigned stacksMax[2000];
int max = 0, stacksFront = 0, stacksRear = 0;

void enter() {
	int height, size = stacks[stacksRear].size;
	scanf("%d", &height);
	if (size >= CAPACITY) {
		stacksRear++;
		size = 0;
	}
	stacks[stacksRear].elem[size++] = height;
	stacks[stacksRear].size++;
	if (height > stacksMax[stacksRear]) {
		stacksMax[stacksRear] = height;
	}
	if (height > max) {
		max = height;
	}
}

void depart() {
	if (frontQ.size == 0) {
		stacksMax[stacksFront] = 0;
		Stack& S = stacks[stacksFront++];
		for (int i = 0; i < S.size; i++) {
			frontQ.elem[i] = S.elem[i];
		}
		frontQ.size = S.size;
		S.size = 0;
		for (int i = frontQ.size - 1, curQMax = 0; i >= 0; i--) {
			if (curQMax < frontQ.elem[i]) {
				maxQ.elem[i] = curQMax = frontQ.elem[i];
			} else {
				maxQ.elem[i] = curQMax;
			}
		}
		maxQ.size = frontQ.size;
		frontQ.front = maxQ.front = 0;
		frontQ.rear = maxQ.rear = S.size;
		if (max == maxQ.elem[0] && stacksFront <= stacksRear) {
			max = stacksMax[stacksFront];
			for (int i = stacksFront; i <= stacksRear; i++) {
				if (stacksMax[i] > max) {
					max = stacksMax[i];
				}
			}
		}
		if (stacksFront > stacksRear) {
			stacksFront = stacksRear = 0;
			stacks[stacksFront].size = 0;
			max = 0;
		}
	}
	printf("%d\n", frontQ.elem[frontQ.front]);
	maxQ.front++; frontQ.front++;
	maxQ.size--; frontQ.size--;
}

void query() {
	int theMax;
	if (frontQ.size == 0) {
		theMax = max;
	} else {
		theMax = max > maxQ.elem[maxQ.front] ? max : maxQ.elem[maxQ.front];
	}
	printf("%d\n", theMax);
}

int main() {
	memset(stacks, 0, sizeof(stacks));
	memset(stacksMax, 0, sizeof(stacksMax));
	
	frontQ.size = frontQ.front = frontQ.rear = 0;
	maxQ.size = maxQ.front = maxQ.rear = 0;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char op[2];
		scanf("%s", op);
		switch (op[0]) {
		case 'E': enter(); break;
		case 'D': depart(); break;
		case 'M': query(); break;
		}
	}
}


//#include <stdio.h>
//#include <memory.h>
//
//int queue[2000000];
//int maxes[2000000];
//int front = 0, rear = 0;
//
//void enter() {
//	int height;
//	scanf("%d", &height);
//	queue[rear] = height;
//	maxes[rear] = height;
//	rear++;
//	for (int i = rear-2; i >= front; i--) {
//		if (maxes[i] < height) {
//			maxes[i] = height;
//		}
//	}
//}
//
//void depart() {
//	printf("%d\n", queue[front++]);
//}
//
//void query() {
//	printf("%d\n", maxes[front]);
//}
//
//int main() {
//	memset(queue, 0, sizeof(queue));
//	memset(maxes, 0, sizeof(maxes));
//	int n;
//	
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		char op[2];
//		int height;
//		scanf("%s", op);
//		switch (op[0]) {
//		case 'E': enter(); break;
//		case 'D': depart(); break;
//		case 'M': query(); break;
//		}
//	}
//}