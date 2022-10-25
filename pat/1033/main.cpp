#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct Station {
     float p, d;
};
float cmax, d, davg;
int n;
Station s[550];

bool cmp(const Station &a, const Station &b) {
    return a.d < b.d;
}

int main() {
    freopen("in1.txt", "r", stdin);
    scanf("%f %f %f %d", &cmax, &d, &davg, &n);
    //printf("%f %f %f %d\n", cmax, d, davg, n);

    for (int i = 0; i < n; ++i) {
        scanf("%f %f", &s[i].p, &s[i].d);
    }
    sort(s, s+n, cmp);
//    for (int i = 0; i < n; ++i) {
//        printf("%.2f %.2f\n", s[i].p, s[i].d);
//    }

    if (s[0].d > 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }


    float tank = 0.0, cost = 0.0;
    int i;
    for (i = 0; i < n-1; ++i) {
         if (((s[i+1].d - s[i].d) / davg) > cmax) {
             printf("The maximum travel distance = %.2f\n", s[i].d + cmax*davg);
             break;
         } else if (s[i+1].p < s[i].p) {
             if ((s[i+1].d - s[i].d) / davg > tank) {
                cost += ((s[i+1].d - s[i].d) / davg - tank) * s[i].p;
                tank = 0.0;
             } else {
                tank -= (s[i+1].d - s[i].d) / davg;
             }
         } else {
             int j = 1;
             while ((i+j) < n && (s[i+j].d - s[i].d) / davg <= cmax && s[i+j].p > s[i].p) {
                j++;
             }
             if (i + j == n) {
                if ((d - s[i].d) / davg > cmax) {
                    cost += (cmax - tank) * s[i].p;
                    tank = cmax - (s[i+1].d - s[i].d) / davg;
                } else {
                    cost += ((d - s[i].d) / davg - tank) * s[i].p;
                    tank = (d-s[i].d) / davg - (s[i+1].d - s[i].d) / davg;
                }
             } else if ((s[i+j].d - s[i].d) / davg > cmax) {
                 cost += (cmax - tank) * s[i].p;
                 tank = cmax - (s[i+1].d - s[i].d) / davg;
             } else {
                 cost += ((s[i+j].d - s[i].d) / davg - tank) * s[i].p;
                 tank = (s[i+j].d-s[i].d) / davg - (s[i+1].d-s[i].d) / davg;
             }
         }
         //printf("cost=%.2f tank=%f\n", cost, tank);
    }
    if (i == n-1) {
        if ((d - s[i].d) / davg > cmax) {
            printf("The maximum travel distance = %.2f\n", s[i].d + cmax*davg);
        } else {
            cost += ((d-s[i].d)/davg - tank) * s[i].p;
            tank = 0;
            printf("%.2f\n", cost);
        }
    }
    return 0;
}
