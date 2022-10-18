#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>

using namespace std;
vector<string> mapx[2505];

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    freopen("in.txt", "r", stdin);

    int n,k,c,x;
    char ch[10];
    string s;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%s%d",ch,&c);
        s=string(ch);
        for(int j=0;j<c;++j)
        {
            scanf("%d",&x);
            mapx[x].push_back(s);
        }
    }
    int len;
    for (int i = 1; i <= k; ++i) {
         len = mapx[i].size();
         printf("%d %d\n", i, len);
         sort(mapx[i].begin(), mapx[i].end());
         for (int j = 0; j < len; ++j) {
             printf("%s\n", mapx[i][j].c_str());
        }
    }
    return 0;
}
