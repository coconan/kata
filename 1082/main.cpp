#include <iostream>
#include <string>
using namespace std;

int main()
{
	string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string wei[5]={"Shi","Bai","Qian","Wan","Yi"};

	string data;	//��������
	cin>>data;
	int begin=0,end=data.size(),next;	//��ʼλ�ã���β����һ��4λ���ݵ�ͷ
	int flag=0;	//�Ƿ��м����0�ı�־
	if(data[0]=='-')
		begin=1;
	if(end-begin<=1&&data[begin]=='0')	//����0���������
	{
		cout<<"ling";
		return 0;
	}
	if(data[0]=='-')	//������
		cout<<"Fu";
    next=end;
    while(next-4>begin)
        next-=4;
	while(begin<end)
	{
		while(begin<next)	//���
		{
			if(data[begin]-'0'>0)
			{
				if(flag==1)	//����
				{
					cout<<" ling";
					flag=0;
				}
				if(begin>0)	//�������
					cout<<" ";
				cout<<num[data[begin]-'0'];
				if(next-begin-2>=0)	//�����ʮ��λ
					cout<<" "<<wei[next-begin-2];
			}
			else
				flag=1;
			begin++;
		}
		if(end-next>0)	//�������
			cout<<" "<<wei[(end-next)/4+2];
        next += 4;
	}
	return 0;
}
