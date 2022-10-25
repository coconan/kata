#include<iostream>
#include<iomanip>
using namespace std;

float a[1001]={0},b[1001]={0},c[2001]={0};

int main()
{ 
    freopen("D:\\test.txt", "r", stdin);

    int k,n,i,j,d=0;
    cin>>k;
    for(i=0;i<k;i++)
    {
         cin>>n;
         cin>>a[n];
     }
    cin>>k;
    for(i=0;i<k;i++)
    {
	cin>>n;
        cin>>b[n];
    }
    for(i=0;i<1001;i++)
	{
        for(j=0;j<1001;j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
    for(i=0;i<2001;i++)
	{
        if(c[i])
		{
			d++;
		}
	}
    cout<<d;
    for(i=2000;i>=0;i--)
	{
		if(c[i])
		{
			printf(" %d %.1lf",i,c[i]);
		}
	}
	printf("\n");
	return 0;
} 