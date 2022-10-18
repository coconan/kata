#include<iostream>   
#include<vector>  
#include<string>  
#include<algorithm>  
using namespace std; 
  
struct Score  
{  
    string id;  
    int score;  
    int local;  
    int global;  
    int location;  
};  
  
bool sortByScore(Score a,Score b)  
{  
    if(a.score != b.score)  
        return  a.score > b.score;  
    else  
        return a.id < b.id;  
}  
   
int main()  
{  
    vector<Score> globallist;  
    vector<Score> locallist;  
  
    int N;  
    int K;  
  
    cin>>N;  
    for(int n=1;n<=N;n++)  
    {  
        cin>>K;  
        while(K--)  
        {  
            Score s;  
            cin >> s.id;  
            cin >> s.score;  
            s.location = n;  
            locallist.push_back(s);  
        }  
  
        sort(locallist.begin(),locallist.end(),sortByScore);  
        //rank  
        for(int i=0;i<locallist.size();i++)  
        {  
            if(i!=0 && locallist[i].score == locallist[i-1].score)  
                locallist[i].local = locallist[i-1].local;  
            else  
                locallist[i].local = i+1;  
        }  
        //add  
        globallist.insert(globallist.end(),locallist.begin(),locallist.end());  
        locallist.clear();  
    }  
  
    //rank  
    cout<<globallist.size()<<endl;  
    sort(globallist.begin(),globallist.end(),sortByScore);  
    for(int i=0;i<globallist.size();i++)  
    {  
        if(i!=0 && globallist[i].score == globallist[i-1].score)  
            globallist[i].global = globallist[i-1].global;  
        else  
            globallist[i].global = i+1;  
        cout<<globallist[i].id<<" "<<globallist[i].global<<" "<<globallist[i].location<<" "<<globallist[i].local<<endl;  
    }  
}