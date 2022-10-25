#include<iostream>  
#include<string>  
using namespace std;  
  
int add(int n)  
{  
    return 1<<n;  
}  
  
void compare(string str)  
{  
    int len = str.length();  
    int carry = 0;  
    int tmp;  
    int sign1 = 0;  
    int sign2 = 0;  
  
    while(len)  
    {  
        sign1 += add(str[len-1]-'0');  
        tmp = (str[len-1]-'0')*2;  
        str[len-1] = '0' + tmp%10 + carry;  
        sign2 += add(str[len-1]-'0');  
        carry = (tmp+carry)/10;  
        len--;  
    }  
  
    if(sign1==sign2)  
    {  
        cout<<"Yes"<<endl;  
    }  
    else  
    {  
        cout<<"No"<<endl;  
    }  
  
    if(carry == 0)  
        cout<<str<<endl;  
    else  
        cout<<carry<<str<<endl;  
}  
  
int main()  
{  
    string in;  
    cin>>in;  
    compare(in);  
}  