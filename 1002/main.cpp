#include <stdio.h>
#include <cmath>

typedef struct Term {
    int expo;
    double coef;
} Term;

int main() {
    Term a[10], b[10], sum[30];
    int len_a, len_b, i, j, k;
    scanf("%d", &len_a);
    for (int i = 0; i < len_a; ++i) {
        scanf("%d %lf", &a[i].expo, &a[i].coef);
    }
    scanf("%d", &len_b);
    for (int i = 0; i < len_b; ++i) {
        scanf("%d %lf", &b[i].expo, &b[i].coef);
    }
    for (i = 0, j = 0, k = 0; i < len_a && j < len_b; ) {
        if (a[i].expo > b[j].expo) {
            sum[k++] = a[i++];
        } else if (a[i].expo < b[j].expo) {
            sum[k++] = b[j++];
        } else {
            int expo = a[i].expo;
            double coef = a[i++].coef + b[j++].coef;
            if (fabs(coef) > 1e-5) {
                sum[k].expo = expo;
                sum[k++].coef = coef;
            }
        }
    }
    while (i < len_a) { sum[k++] = a[i++]; }
    while (j < len_b) { sum[k++] = b[j++]; }
    printf("%d", k);
    for (i = 0; i < k; ++i) {
        printf(" %d %.1f", sum[i].expo, sum[i].coef);
    }
    printf("\n");
    return 0;
}
