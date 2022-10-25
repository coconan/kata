#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int lowest = 101, highest = -1;
    char fname[15], mname[15], fid[15], mid[15];
    char gender, name[15], id[15];
    int n, grade;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %c %s %d", name, &gender, id, &grade);
        if (gender == 'F') {
            if (grade > highest) {
                strcpy(fname, name);
                strcpy(fid, id);
                highest = grade;
            }
        } else {
            if (grade < lowest) {
                strcpy(mname, name);
                strcpy(mid, id);
                lowest = grade;
            }
        }
    }
    if (highest == -1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", fname, fid);
    }
    if (lowest == 101) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", mname, mid);
    }
    if (highest == -1 || lowest == 101) {
        printf("NA\n");
    } else {
        printf("%d\n", highest - lowest);
    }
    return 0;
}
