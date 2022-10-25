#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int ag, as, ak, bg, bs, bk, carry = 0;
    scanf("%d.%d.%d %d.%d.%d", &ag, &as, &ak, &bg, &bs, &bk);
    ak = ak + bk;
    carry = ak / 29;
    ak = ak % 29;
    as = as + bs + carry;
    carry = as / 17;
    as = as % 17;
    ag = ag + bg + carry;
    printf("%d.%d.%d\n", ag, as, ak);
    return 0;
}
