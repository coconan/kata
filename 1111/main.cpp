#include<stdio.h>
int m, n, k;
int max, min, tmp;
bool flag;
int main()
{
    scanf("%d %d %d", &m, &n, &k);
    while(k --) {
        flag = true;
        max = 0;
        min = 1001;

        for (int i = 0; i != n; ++ i) {
            scanf("%d", &tmp);
            if (tmp > max) {
                if (tmp - i > m) flag = false;
                else max = min= tmp;
            } else {
                if ( tmp > min) flag = false;
                else min = tmp;
            }
        }

        if (flag) printf("YES\n");
        else printf("NO\n");
    }
}
