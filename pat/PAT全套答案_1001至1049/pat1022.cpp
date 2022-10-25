#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

//思路：这题看起来很复杂，主要是考察字符串的操作，尤其注意字符数组的输入方式选择。
//对于  char a[10],①cin>>a;②cin.getline(a,6);③gets(a);④cin.get(a,6);
//若输入"abcd efgh ijkl"回车对应一下结果：
//①a[]={'a','b','c','d','\0'}           strlen(a)=4 ; sizeof(a)=10        //遇到空格、制表符、回车即停止
//②④a[]={'a','b','c','d',' ','\0'}   strlen(a)=5 ; sizeof(a)=10        //遇到回车停止
//③a[]={'a','b','c','d',' ','e','f','g','h',' ','i','j','k','l'}  strlen(a)=14 ; sizeof(a)=10  //溢出错误
//在使用cin>>a或cin>>n后，想要使用gets(a)或cin.getline(a,n) 需要先使用cin.ignore()忽略掉空格和回车。
//使用ch=cin.get()或cin.get(ch)获取一个字符（可用来寻找回车符'\n'）。

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
	cin.ignore();     //忽略n后面的回车符
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
				break;   //判断是否为回车符，表示关键字结束 //没有cin.getchar()
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
		cin.ignore();       //忽略空格获回车符
		gets(search);
		cout<<num<<" "<<search<<endl;
		string str=search;
		query(search,str);
	}
	return 0;
}