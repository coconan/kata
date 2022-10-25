#include <iostream>
#include <string>
using namespace std;
int main()
{
 string a;
 getline(cin,a);
 int i,j,max = 0,n=a.size();
 for(i=0;i<n;i++)
 {
  //最长回文串的长度为奇数
  for(j=0;i-j>=0&&i+j<n;j++)
  {
   if(a[i-j]!=a[i+j])
    break;
   if(max<2*j+1)
    max=2*j+1;
  }
  //最长回文串的长度为偶数
  for(j=0;i-j>=0&&i+j+1<n;j++)
  {
   if(a[i-j]!=a[i+j+1])
    break;
   if(max<2*j+2)
    max=2*j+2;
  }
 }
 cout<<max<<endl;
 return 0;
}