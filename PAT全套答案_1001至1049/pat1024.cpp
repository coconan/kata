#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string s1,string s2)
{
	int carry = 0;
	string result = "";
	int len1 = s1.length();
	//int len2 = s2.size();
	int sum;
	int i;
	for(i=len1-1;i>=0;i--)
	{
		sum = s1[i]-'0'+s2[i]-'0';
		sum += carry;
		result.insert(result.begin(),sum%10+'0');
		carry = sum/10;
	}
	
	if(carry)
		result.insert(result.begin(),carry+'0');

	return result;
}

int main()
{
	string str;
	int K;
	int k = 0;
	string rstr;
	cin>>str;
	cin>>K;
	while(k<K)
	{
		rstr = str;
		reverse(str.begin(),str.end());
		if(rstr == str)
			break;
		else
			str = add(str,rstr);
		k++;
	}
	cout<<str<<endl;
	cout<<k<<endl;
}