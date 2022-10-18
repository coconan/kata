#include <stdio.h>
#include <cstring>

int main(){
    int a, b, sum, i, j, k;
    char temp[10], output[10];
    scanf("%d %d", &a, &b);
    sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = -sum;
    }
    sprintf(temp, "%d", sum);
    for (i = strlen(temp)-1, j = 0, k = 0; i >= 0; ++k) {
        if (j == 3) {
            output[k] = ',';
            j = 0;
        } else {
            output[k] = temp[i--];
            ++j;
        }
    }
    for (i = k-1; i >= 0; --i) {
        printf("%c", output[i]);
    }
    printf("\n");
    return 0;
}
