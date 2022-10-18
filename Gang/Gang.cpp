//****************************************
//*程 序：Gang.cpp                       *
//*作 者：ytm                            *
//*时 间：2013-2-26                      *
//*功 能：编程题库/浙江大学-机试/2012 第 *
//*       四题                           *
//****************************************

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef struct {
    int duration;
    int head;
    char name[20];
}Member;
typedef struct {
    int numOfMembers;
    char headName[20];
}Gang;

bool compare(Gang a, Gang b) {
    if(strcmp(a.headName, b.headName) < 0) {
        return true;
    } else {
        return false;
    } 
}

int getIndex(char name[], Member members[], int &numOfMembers) {
    int i = 0;
    for ( i = 0; i < numOfMembers; i++) {
        if ( !strcmp(members[i].name,name) ) {
            return i;   
        }
    }
    numOfMembers++;
    strcpy(members[i].name, name);
    members[i].head = -1;
    members[i].duration = 0;
    return i;
}

int findHead(Member members[], int index) {
    if(members[index].head > 0) {
        members[index].head = findHead(members, members[index].head);
        return members[index].head;
    } else {
        return index;
    }
}

void mergeSet(Member members[], int index1, int index2) {
     int i, j;
     i = findHead(members, index1);
     j = findHead(members, index2);
     if(members[index1].duration > members[i].duration) {
         members[index1].head = members[i].head;
         members[i].head = index1;
         i = index1;
     }
     if(members[index2].duration > members[j].duration) {
         members[index2].head = members[j].head;
         members[j].head = index2;
         j = index2;
     }
     if(members[i].duration > members[j].duration) {
         members[i].head += members[j].head;
         members[j].head = i;
     } else {
         members[j].head += members[i].head;
         members[i].head = j;   
     }
}

int main(){
    Member members[2000];
    Gang gangs[2000];
    int n, k, i, j, numOfMembers = 0, duration, numOfGangs = 0;
    int index1, index2, gangHead;
    char name1[20], name2[20];
    scanf("%d%k", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%s%s%d", name1, name2, &duration);
        index1 = getIndex(name1, members, numOfMembers);
        index2 = getIndex(name2, members, numOfMembers);
        members[index1].duration += duration;
        members[index2].duration += duration;
        mergeSet(members, index1, index2);
    }
    for(i = 0; i < numOfMembers; i++) {
        gangHead = findHead(members, i);
        if (members[gangHead].duration > k && abs(members[gangHead].head) > 2) {
            for ( j = 0; j < numOfGangs; j++) {
                if( !strcmp(gangs[j].headName, members[gangHead].name) ) break;
            }
            if( j == numOfGangs ) {
                strcpy(gangs[numOfGangs].headName, members[gangHead].name);
                gangs[numOfGangs].numOfMembers = abs(members[gangHead].head);
                numOfGangs++;
            }
        }
    }
    if(numOfGangs > 0) {
        sort(gangs, gangs + numOfGangs, compare);
        printf("%d\n", numOfGangs);
        for( i = 0; i < numOfGangs; i++) {
             printf("%s %d", gangs[i].headName, gangs[i].numOfMembers);
        }    
    } else {
        printf("0\n");
    }   
    return 0;
}
