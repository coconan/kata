#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
struct Student {
    int weight;
    int srank;
};
Student s[10000];
int winners[10000];
int playorder[10000];
int n, ng, nwinner, nplayer;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &ng);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i].weight);
    }

    nplayer = n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &playorder[i]);
    }
    while (nplayer > 1) {
        nwinner = 0;
        for (int i = 0; i < nplayer; i+=ng) {
            int winner = playorder[i];
            for (int j = 0; i+j < nplayer && j < ng; ++j) {
                if (s[playorder[i+j]].weight > s[winner].weight) {
                    winner = playorder[i+j];
                }
            }
            winners[nwinner++] = winner;
            //printf("winner= %d ", winner);
        }
        for (int i = 0; i < nplayer; ++i) {
            s[playorder[i]].srank = nwinner+1;
        }
        nplayer = nwinner;
        for (int i = 0; i < nwinner; ++i) {
            playorder[i] = winners[i];
        }
        //printf("\n");
    }
    s[playorder[0]].srank = 1;
    printf("%d", s[0].srank);
    for (int i = 1; i < n; ++i) {
        printf(" %d", s[i].srank);
    }
    return 0;
}
