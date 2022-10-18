#include <iostream>
#include <stdio.h>

using namespace std;
int diamonds[100005];
int mings[100005];
int minge[100005];
int mincounter = 0;
int n, m;

int main() {
    freopen("in1.txt", "r", stdin);;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &diamonds[i]);
    }
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", diamonds[i]);
//    }
    int mins = 999999999;
    bool hasequal = false;
    for (int i = 0, j = 0, sum = 0; i < n; ) {
        //printf("i=%d j=%d sum=%d mins=%d\n", i, j, sum, mins);
        if (sum < m) {
            if (j < n) {
                sum += diamonds[j++];
            } else {
                break;
            }
        } else if (sum > m) {
            if (sum < mins) {
                mins = sum;
                mings[0] = i+1;
                minge[0] = j;
                mincounter = 1;
            } else if (sum == mins) {
                mings[mincounter] = i+1;
                minge[mincounter] = j;
                mincounter++;
            }
            sum -= diamonds[i++];
        } else {
           hasequal = true;
           printf("%d-%d\n", i+1, j);
           if (j < n) {
               sum = sum - diamonds[i++] + diamonds[j++];
           } else {
               break;
           }
        }
    }
    if (!hasequal) {
        for (int i = 0; i < mincounter; ++i) {
            printf("%d-%d\n", mings[i], minge[i]);
        }
    }
    return 0;
}
