#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 using namespace std;
 
 int N,K,wait_time=0;
 struct Customer 
 {
     int arrive_time;
     int need_time;
 };
 
 struct Customer customer[10002];
 
 struct Windows
 {
     int next_available_time;
 };
 
 struct Windows windows[102];
 
 bool cmp(struct Customer a,struct Customer b)
 {
     return a.arrive_time<b.arrive_time;
 }
 
 int find_available_windows(int arrive_time)
 {
     int i;
     for(i=0;i<K;i++) {
         if(windows[i].next_available_time<=arrive_time) {
             return i;
         }
     }
     return -1;
 }
 
 int find_earliest_window()
 {
     int i;
     int e=0;
     for(i=1;i<K;i++) {
         if(windows[i].next_available_time<windows[e].next_available_time) {
             e=i;
         }
     }
     return e;
 }
 
 int main()
 {
     scanf("%d%d",&N,&K);
     int i;
     char arrive_time[20];
     int need_time;
     for(i=0;i<K;i++) 
         windows[i].next_available_time=3600*8;
     int len=0;
     for(i=0;i<N;i++) {
         int h,m,s;
         scanf("%s%d",arrive_time,&need_time);
         if(strcmp(arrive_time,"17:00:00")>0)
             continue;
         
         sscanf(arrive_time,"%d:%d:%d",&h,&m,&s);
         if(h<8)
             wait_time+=8*3600-(3600*h+60*m+s);
         customer[len].arrive_time=3600*h+60*m+s;
         customer[len++].need_time=need_time*60;
     }
     N=len;
 
     sort(customer,customer+N,cmp);
 
     for(i=0;i<N;i++) {
         int w=find_available_windows(customer[i].arrive_time);
         if(w>=0) {//找到空闲窗口
         //    windows[w].next_available_time=customer[i].arrive_time+customer[i].need_time;
             if(customer[i].arrive_time<8*3600) {
                 windows[w].next_available_time=8*3600+customer[i].need_time;
             } else {
                 windows[w].next_available_time=customer[i].arrive_time+customer[i].need_time;
             }
         } else { //找不到空闲窗口
             w=find_earliest_window();
         /*    wait_time+=windows[w].next_available_time-customer[i].arrive_time;
         *    windows[w].next_available_time=(windows[w].next_available_time-customer[i].arrive_time)+customer[i].need_time;
         */
             if(customer[i].arrive_time<8*3600) {//如果到得早 窗口的下个可用时间等于当前下个可用时间加新来顾客所需要服务时间
                 wait_time+=windows[w].next_available_time-8*3600;
                 windows[w].next_available_time=windows[w].next_available_time+customer[i].need_time;
             } else {
                 wait_time+=windows[w].next_available_time-customer[i].arrive_time;
                 windows[w].next_available_time=windows[w].next_available_time+customer[i].need_time;
             }                
 
         }
     }
 
     printf("%.1f\n",1.0*wait_time/60.0/N);
 }