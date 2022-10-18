//****************************************
//*�� ��Sharing.cpp                    *
//*ʱ �䣺2013-2-25                      *
//*�� �ߣ�ytm                            *
//*�� �ܣ�������/�㽭��ѧ-����/2012 �� *
//*       ����                           *
//****************************************

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct {
    int next;
    bool visited;
}Node;

int main() {
	Node array[100000];
	memset(array, 0, sizeof(array));
	int addr1, addr2, addr, next, total, i;
	scanf("%d%d%d", &addr1, &addr2, &total);
	for(i = 0; i < total; i++) {
		scanf("%d%*s%d", &addr, &next);
		array[addr].next = next;
	}
    while(addr1 != -1) {
        array[addr1].visited = true;
        addr1 = array[addr1].next;
    }
    while(addr2 != -1) {
        if(array[addr2].visited) break;
        addr2 = array[addr2].next;
    }
    printf(addr2 == -1 ? "%d" : "%05d",  addr2);
    system("pause");
	return 0;
}

