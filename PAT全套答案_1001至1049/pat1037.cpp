#include<iostream>  
#include<algorithm>  
using namespace std;  
  
int coupon[1000000];  
int product[1000000];  
  
int main()  
{  
    int coupon_cnt, product_cnt;  
    bool bFirstCase = true;  
    while(cin>>coupon_cnt && coupon_cnt > 0) {  
        for(int i = 0; i < coupon_cnt; ++i)  
            cin>>coupon[i];  
        cin>>product_cnt;  
        for(int i = 0; i < product_cnt; ++i)  
            cin>>product[i];  
        // sort array  
        sort(coupon, coupon + coupon_cnt);  
        sort(product, product + product_cnt);  
        // calculate  
        int sum = 0;  
        int steps = (coupon_cnt < product_cnt) ? coupon_cnt : product_cnt;  
        // backward  
        for(int i = 0; i < steps; ++i) {  
            if(coupon[i] >= 0 || product[i] >= 0)  
                break; // stop for loop  
            sum += coupon[i] * product[i];  
        }  
        // forward  
        for(int i = 0; i < steps; ++i) {  
            if(coupon[coupon_cnt - 1 - i] <= 0 ||  
                product[product_cnt - 1 -i] <= 0)  
                break; // stop for loop  
            sum += coupon[coupon_cnt - 1 - i] * product[product_cnt - 1 - i];  
        }  
        // output  
        if(!bFirstCase) cout<<"\n";  
        cout<<sum;  
        if(bFirstCase) bFirstCase = false;  
    }  
    return 0;  
}  