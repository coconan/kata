 #include <stdio.h>
 #include <string.h>
 #include <math.h>
    
int Char_To_Int(char c){
    if(c>='0' && c<='9')
        return c - '0';
    else
        return c - 'a' + 10;
    }
long long Char_To_Demical(char *x,long long radix){
    int length = strlen(x);
    int i;
    long long ans = 0;
    for(i = 0;i < length;i++){
        ans *= radix;
        ans += Char_To_Int(x[i]);
        if(ans < 0)
            return -1;
    }
    return ans;
}
    
int main(void){
    char n1[100],n2[100],temp[100];
    int tag;
    int i,j;
    long long temp1,temp2;
    long long radix,ans;
    long long low,high;
    int flag;
    scanf("%s%s%d%lld",n1,n2,&tag,&radix);
    flag = 0;
    if(tag == 2){
        strcpy(temp,n1);
        strcpy(n1,n2);
        strcpy(n2,temp);
    }
    temp1 = Char_To_Demical(n1,radix);
    low = 2;
    for(i = 0;i < strlen(n2);i++){
        j = Char_To_Int(n2[i]);
        if(j >= low)
            low = j+1;
    }
    high = temp1+1;
    while(low <= high){
        ans = (low+high)/2;
        temp2 = Char_To_Demical(n2,ans);
        if(temp2 == -1 || temp2 > temp1){
            high = ans-1;
        }
        else if(temp2 < temp1){
            low = ans+1;
        }
        else if(temp2 == temp1){
            flag = 1;
            break;
        }
    }
    if(flag) 
        printf("%lld\n",ans);
    else
        printf("Impossible\n");
    return 0;
}