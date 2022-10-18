#include <cstdio>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

const int MAXS = 60*1024*1024;
const int MAXN = 10000000;

int numbers[MAXN];
char buf[MAXS];

void analyse(char *buf,int len = MAXS)
{
    int i;
    numbers[i=0]=0;
    for (char *p=buf;*p && p-buf<len;p++)
        if (*p == ' ' || *p == '\n')
            numbers[++i]=0;
        else
            numbers[i] = numbers[i] * 10 + *p - '0';
}

void fread_analyse()
{
    freopen("test.txt","rb",stdin);
    int len = fread(buf,1,MAXS,stdin);
    buf[len] = '\0';
    analyse(buf,len);
}

struct Point {
	int x, y;
};

Point arr[5000005];

int main() {
	long long n = 10000000;
	long long x, y;
	time_t start, end;
	start = time(NULL);
	freopen("test.txt", "r", stdin);
	scanf("%lld", &n);
	for (long long i = 0; i < 5000000; i++) {
		scanf("%d%d", &arr[i].x, &arr[i].y);
	}
	end = time(NULL);
	printf("%f\n", difftime(end, start));



	int starti = clock();
	fread_analyse();
	printf("%.3lf\n", double(clock()-starti)/CLOCKS_PER_SEC);
	for (int i = 1; i < 1000; i *= 2) {
		printf("arr[i].x=%d arr[i].y=%d\n", arr[i].x, arr[i].y);
		printf("numbers[2*i]=%d numbers[2*i+1]=%d\n", numbers[2*i+1], numbers[2*i+2]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", numbers[i]);
	}
	return 0;
}