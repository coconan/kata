//#include <iostream>
//
//using namespace std;
//
//int wall[20][20], penpoint[20][20];
//
//int pow(int x, int y) {
//	int result = 1;
//	for (int i = 0; i < y; i++) {
//		result *= x;
//	}
//	return result;
//}
//
//void fill(int n) {
//	for (int r = 1; r < n; r++) {
//		for (int c = 1; c <= n; c++) {
//			penpoint[r+1][c] = (wall[r][c] + penpoint[r][c] + penpoint[r-1][c]
//								+ penpoint[r][c+1] + penpoint[r][c-1] + 1) % 2;
//		}
//	}
//}
//
//bool check(int n) {
//	for (int c=1; c <= n; c++) {
//		int state = (wall[n][c] + penpoint[n-1][c] + penpoint[n][c-1] 
//					+ penpoint[n][c+1] + penpoint[n][c]) % 2;
//		if (state != 1) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool enumerate(int n) {
//	for (int i = 0; i < pow(2, n); i++) {
//		fill(n);
//		if (check(n)) {
//			return true;
//		}
//		penpoint[1][1]++;
//		int c = 1;
//		while(penpoint[1][c] > 1) {
//			penpoint[1][c] = 0;
//			c++;
//			penpoint[1][c]++;
//		}
//	}
//	return false;
//}
//
//int count(int n) {
//	int counter = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (penpoint[i][j] == 1) {
//				counter++;
//			}
//		}
//	}
//	return counter;
//}
//
//int main() {
//	int n = 4;
//	char brickColor;
//	
//	for (int i = 0; i < 1; i++) {
//		for (int j = 0; j <= n+1; j++) {
//			wall[0][j] = 0;
//			wall[j][0] = 0;
//			wall[j][n+1] = 0;
//		}
//		for (int j = 1; j <= n; j++) {
//			for (int k = 1; k <= n; k++) {
//				cin >> brickColor;
//				wall[j][k] = brickColor=='w';
//			}
//		}
//		for (int k = 0; k < n+2; k++) {
//			for (int l = 0; l < n+2; l++) {
//				penpoint[k][l] = 0;
//			}
//		}
//		unsigned counter1;
//		if (enumerate(n)) {
//			counter1 = count(n);
//		} else {
//			counter1 = ~0; 
//		}
//		for (int j = 0; j <= n+1; j++) {
//			wall[0][j] = 1;
//			wall[j][0] = 1;
//			wall[j][n+1] = 1;
//		}
//		for (int j = 1; j <= n; j++) {
//			for (int k = 1; k <= n; k++) {
//				wall[j][k] = wall[j][k]? 0 : 1;
//			}
//		}
//		for (int k = 0; k < n+2; k++) {
//			for (int l = 0; l < n+2; l++) {
//				penpoint[k][l] = 0;
//			}
//		}
//		unsigned counter2;
//		if (enumerate(n)) {
//			counter2 = count(n);
//		} else {
//			counter2 = ~0; 
//		}
//		if (counter1 < counter2) {
//			cout << counter1 << endl;
//		} else if (counter1 > counter2) {
//			cout << counter2 << endl;
//		} else {
//			if (counter1 != ~0) {
//				cout << counter1 << endl;
//			} else {
//				cout << "Impossible" << endl;
//			}
//		}
//	}
//}

#include<iostream>
#define MAX 65536
using namespace std;
struct Node {
	int prev;
	int i, j;
	int id;
};
Node que[MAX*2];
int front,rear;
bool isVis[MAX];    //记录状态是否已经出现过
int step[MAX];        //记录到达id==i的状态所需翻转次数
int main(){
    char color;
    int id=0,tmp;
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){     //输入初始状态并转换为id
            cin>>color;
            id<<=1;
            if(color=='b')id+=1;
        }
    }
    if(id==0||id==65535){cout<<0<<endl;return 0;}   //如果初始状态已经满足要求直接输出
	Node node;
	node.id = id;
	node.i = -1;
	node.j = -1;
	node.prev = -1;
    que[rear++]=node;      //将初始状态id入队
    isVis[id]=true;
    step[id]=0;   //到达初始状态所需次数为0
    bool flag = false;
	while(front<rear && !flag){   //如果队列不为空，继续操作
		Node head;
        head=que[front++];   //将队头元素出队
		id=head.id;
        for(i=0;i<4 && !flag;i++)
            for(j=0;j<4 && !flag;j++){
                tmp=id;       //需要遍历队头元素的16种操作，每次都要还原tmp
                if(i==0)tmp^=1<<(11-4*i-j);          //翻转的位置为15-(4*(i+1)+j)
                else if(i==3)tmp^=1<<(19-4*i-j);   //翻转的位置为15-(4*(i-1)+j)
                else{
                    tmp^=1<<(11-4*i-j);
                    tmp^=1<<(19-4*i-j);
                }
                if(j==0)tmp^=3<<(14-4*i-j);          //翻转的位置为15-(4*i+j)、15-(4*i+j+1)
                else if(j==3)tmp^=3<<(15-4*i-j);  //翻转的位置为15-(4*i+j-1)、15-(4*i+j)
                else{
                    tmp^=7<<(14-4*i-j);                //翻转的位置为15-(4*i+j-1)、15-(4*i+j)、15-(4*i+j+1)
                }
                if(!isVis[tmp]){      //如果是新的状态，入队
					Node newNode;
					newNode.id=tmp;
					newNode.i = i;
					newNode.j = j;
					newNode.prev = front-1;
                    que[rear++]=newNode;
                    isVis[tmp]=true;
                    step[tmp]=step[id]+1;   //当前次数=到达队头元素所需次数+1
                }
				if(tmp==0||tmp==65535){
                    flag = true;
                }
            }
    }
	if (flag) cout << step[tmp] << endl;
	else cout<<"Impossible"<<endl;
	node = que[rear-1];
	while (node.prev >= 0) {
		cout << node.i << " " << node.j << endl;
		node = que[node.prev];
	}
    return 0;
}