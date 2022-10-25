#include<iostream>
using namespace std;

#define CARD_LEN 54
char type[] = {'S','H','C','D','J'};

void Print(int tar)
{
     printf("%c",type[tar/13]);
     printf("%d",tar%13+1);
}
 
int main(void){
    int repeat_time;
    int stack[2][CARD_LEN],shuffle[CARD_LEN];
    int pstack = 0;

    for(int i=0;i<CARD_LEN;i++)stack[pstack][i] = i;
    
    scanf("%d",&repeat_time);
    for(int i=0;i<CARD_LEN;i++){
            int temp;
            scanf("%d",&temp);
            shuffle[i] = temp-1;
    }
    
    while(repeat_time--)
    {
            int dstack = pstack^1;
            for(int i=0;i<CARD_LEN;i++)
            {
                    stack[dstack][shuffle[i]] = stack[pstack][i];
            }
            pstack = dstack;
    }
    
    for(int i=0;i<CARD_LEN-1;i++)
    {
            Print(stack[pstack][i]);
            printf(" ");
    }
    Print(stack[pstack][CARD_LEN-1]);
    printf("\n");
    
    return 0;
}