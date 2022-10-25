#include <iostream>
#include <cmath>

using namespace std;

int l[10] = {1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000};
int power[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int f(int x) {
    if (x == 0) return 0;
    if (1 <= x && x <= 9) return 1;
    int p;
    for (p = 9; p >= 1; --p) {
        if (x >= power[p]) break;
    }
    int ret = (x / power[p]) * l[p-1];
    if (x / power[p] == 1) {
        ret += x % power[p] + 1;
    } else {
        ret += power[p];
    }
    return ret + f(x % power[p]);
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}


//#include<stdio.h>
//#include<stdlib.h>

//long long howmanyones1(int N)
//{
//	int temp=N;
//	int i=0;
//	int dec[20];
//	int o[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
//	while(temp>0)
//	{
//		dec[i++]=temp%10;
//		temp/=10;
//	}
//	long long ones=0;
//	i--;
//	while(i>0)
//	{
//		int d=dec[i];
//		if(d==1)
//			ones+=o[i-1]*i+N-o[i]+1;
//		else if(d!=0)
//			ones+=d*o[i-1]*i+o[i];
//		N-=d*o[i];
//		i--;
//	}
//	if(dec[0]>0)
//		ones++;
//	return ones;
//}
//
//int main(void)
//{
//	int N;
//	scanf("%d",&N);
//
//	printf("%ld",howmanyones1(N));
//
//	return 0;
//}
