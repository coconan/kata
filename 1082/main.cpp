#include <iostream>
#include <string>
using namespace std;

int main()
{
	string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string wei[5]={"Shi","Bai","Qian","Wan","Yi"};

	string data;	//输入数据
	cin>>data;
	int begin=0,end=data.size(),next;	//起始位置，超尾，下一个4位数据的头
	int flag=0;	//是否中间出现0的标志
	if(data[0]=='-')
		begin=1;
	if(end-begin<=1&&data[begin]=='0')	//处理0的特殊情况
	{
		cout<<"ling";
		return 0;
	}
	if(data[0]=='-')	//处理负号
		cout<<"Fu";
    next=end;
    while(next-4>begin)
        next-=4;
	while(begin<end)
	{
		while(begin<next)	//输出
		{
			if(data[begin]-'0'>0)
			{
				if(flag==1)	//补零
				{
					cout<<" ling";
					flag=0;
				}
				if(begin>0)	//非零输出
					cout<<" ";
				cout<<num[data[begin]-'0'];
				if(next-begin-2>=0)	//输出个十百位
					cout<<" "<<wei[next-begin-2];
			}
			else
				flag=1;
			begin++;
		}
		if(end-next>0)	//输出万亿
			cout<<" "<<wei[(end-next)/4+2];
        next += 4;
	}
	return 0;
}
