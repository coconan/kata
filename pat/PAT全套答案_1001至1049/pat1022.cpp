#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

//˼·�����⿴�����ܸ��ӣ���Ҫ�ǿ����ַ����Ĳ���������ע���ַ���������뷽ʽѡ��
//����  char a[10],��cin>>a;��cin.getline(a,6);��gets(a);��cin.get(a,6);
//������"abcd efgh ijkl"�س���Ӧһ�½����
//��a[]={'a','b','c','d','\0'}           strlen(a)=4 ; sizeof(a)=10        //�����ո��Ʊ�����س���ֹͣ
//�ڢ�a[]={'a','b','c','d',' ','\0'}   strlen(a)=5 ; sizeof(a)=10        //�����س�ֹͣ
//��a[]={'a','b','c','d',' ','e','f','g','h',' ','i','j','k','l'}  strlen(a)=14 ; sizeof(a)=10  //�������
//��ʹ��cin>>a��cin>>n����Ҫʹ��gets(a)��cin.getline(a,n) ��Ҫ��ʹ��cin.ignore()���Ե��ո�ͻس���
//ʹ��ch=cin.get()��cin.get(ch)��ȡһ���ַ���������Ѱ�һس���'\n'����

struct Book
{
	char id[8];
	char title[81];         
	char author[81];
	vector<string>keywords;
	char publisher[81];
	char pubYear[5];
}; 

vector<Book>book;

int n;

bool cmp(Book a,Book b)
{
	if(strcmp(a.id,b.id)>0)return false;
	else return true;
};


void query(char c[],string str)
{
	int i;
	bool flag=false;
	bool notFound=true;
	for(i=0;i<n;i++)
	{
		if(strcmp(c,book[i].title)==0)flag=true;
		else if(strcmp(c,book[i].author)==0)flag=true;
		else if(strcmp(c,book[i].publisher)==0)flag=true;
		else if(strcmp(c,book[i].pubYear)==0)flag=true;
		else 
		{
			
			int len=book[i].keywords.size();
			for(int j=0;j<len;j++)
			{
				if(str==book[i].keywords[j])
				{
					flag=true;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<book[i].id<<endl;
			flag = false;
			notFound=false;
		}
	}
	if(notFound)
		cout<<"Not Found"<<endl;
}

int main()
{
	//freopen("D://test.txt","r",stdin);

	cin>>n;
	cin.ignore();     //����n����Ļس���
	char key[11];
	int m,i;
	
	for(i=0;i<n;i++)
	{
		Book buf;
		gets(buf.id);
		gets(buf.title);
		gets(buf.author);
		int j=0;
		while(cin>>key)
		{
			buf.keywords.push_back(key);
			if(cin.get()=='\n')
				break;   //�ж��Ƿ�Ϊ�س�������ʾ�ؼ��ֽ��� //û��cin.getchar()
		}
		gets(buf.publisher);
		gets(buf.pubYear);
		book.push_back(buf);
	}
	sort(book.begin(),book.end(),cmp);
	cin>>m;
	char num[3];
	char search[81];
	for(i=0;i<m;i++)
	{
		cin>>num;
		cin.ignore();       //���Կո��س���
		gets(search);
		cout<<num<<" "<<search<<endl;
		string str=search;
		query(search,str);
	}
	return 0;
}