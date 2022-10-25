#include <iostream>  
#include <memory.h>  
using namespace std;  
  
int count[100]={0};  
int maxlevel=1;  
  
struct childLink  //孩子链表  
{  
    int id;  
    childLink *next;  
    childLink(){next=0;}  
};  
  
struct Node     //树节点  
{  
    int childNum;  
    childLink *childHead;  
    Node(){childNum=0;childHead=0;}  
}*node;  
  
void countLeaves(int l,int id)        //嵌套求解不同层次节点中叶子节点的个数  
{  
    childLink *cl = node[id].childHead;  
    l++;  
    while(cl)  
    {         
        if(maxlevel<l)maxlevel=l;  
        if(node[cl->id].childNum==0)count[l]++;  
        else countLeaves(l,cl->id);  
        cl=cl->next;  
    }  
}  
  
int main()  
{  
   
    int n,m;  
    int i,j,id;  
    cin>>n>>m;  
    node=(Node *)malloc(sizeof(Node)*(n+1));  
    memset(node,0,sizeof(Node)*(n+1));  
    childLink *cl=0;  
    for(i=0;i<m;i++)  
    {  
        cin>>id;  
        cin>>node[id].childNum;  
        for(j=0;j<node[id].childNum;j++)  
        {  
            cl = new childLink;  
            cin>>cl->id;  
            if(node[id].childHead) cl->next=node[id].childHead;  
            node[id].childHead = cl;  
        }  
    }  
  
    if(node[1].childNum==0){count[0]=1;maxlevel=0;}  
    else   
    {  
        count[0]=0;  
        countLeaves(0,1);  
    }  
    //cout<<"maxlevel: "<<maxlevel<<endl;  
    for(i=0;i<maxlevel;i++)  
        cout<<count[i]<<" ";  
    cout<<count[i]<<endl;  
    return 0;  
}  