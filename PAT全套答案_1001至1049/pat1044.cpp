#include<iostream>

#define DIAMOND_NUM 100000

using namespace std;

struct
{
        int left;
        int right;
}AnsList[DIAMOND_NUM];

class Ans{
public:
       int payment;
       int pointer;
};

int main(void){
    
    int payment,pLeft,pRight;
    int diamond_num,price;
    int Diamond[DIAMOND_NUM];
    Ans a;
    a.pointer = 0;
    
    scanf("%d%d",&diamond_num,&price);
    
    payment = 0;
    for(int i=0;i < diamond_num;i++){
            scanf("%d",Diamond+i);
            if(payment < price)payment += Diamond[i];
    }
    
    a.payment = payment;
    
    payment = 0;
    pLeft = pRight = 0;
    
    while(pRight <= diamond_num)
    {
         if(payment < price){
             if(pRight >= diamond_num)break;
             payment += Diamond[pRight];
             pRight++;
         }
         else
         {
             if(payment == a.payment)
             {
                  (AnsList[(a.pointer)]).left = pLeft+1;
                  (AnsList[(a.pointer)]).right = pRight;
                  a.pointer++;
             }
             else if(payment < a.payment)
             {
                  a.payment = payment;
                  a.pointer = 0;
                  (AnsList[a.pointer]).left = pLeft+1;
                  (AnsList[a.pointer]).right = pRight;
                  a.pointer++;
             }
             
             payment -= Diamond[pLeft];
             pLeft++;
         }
    }
    
    for(int i=0;i<a.pointer;i++)
    {
            printf("%d-%d\n",AnsList[i].left,AnsList[i].right);
    }
    
    return 0;
}