#include <cstdio>
#include <cstring>
using namespace std;

int  node[100000],temp[100000];

int main()
{
    memset(node,-1,sizeof(node));

    int start1,start2,n,from,to;
    char s[2];

    scanf("%d %d %d",&start1,&start2,&n);
    for( int i=0; i<n; i++)
    {
        scanf("%d %s %d",&from,s,&to);
        node[from] = to;
    }
    while(start1 != -1)
    {
        temp[start1] = 1;
        start1 = node[start1];
    }
    while(start2 != -1)
    {
        if(temp[start2])
        {
            printf("%.5d\n",start2);
            return 0;
        }
        start2 = node[start2];
    }
    printf("-1\n");
    return 0;
}