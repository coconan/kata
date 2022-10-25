#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
struct people{
	char name[5];
	int id;	
}str[40001];

int cnt[2501];
vector<int> buf[2501];
char bucket[40001];

bool mycmp(const struct people &a, const struct people &b) {
	return strcmp(b.name, a.name)>0;
}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &K);
	int tmp;
	int k;
	for (int i=1; i<=N; ++i) {
		str[i].id = i;
		scanf("%s %d", str[i].name, &tmp);
		for (int j=0; j<tmp; ++j) {
			scanf("%d", &k);	
			++cnt[k];
			buf[k].push_back(i);
		}
	}
	sort(str+1, str+1+N, mycmp);
	vector<int>::iterator itr;
	for (int i=1; i<=K; ++i) {
		printf("%d %d\n", i, cnt[i]);
		
		for (itr = buf[i].begin(); itr != buf[i].end(); ++itr) {
			bucket[*itr] = 1;
		}
		for (int j=1; j<=N; ++j) {
			if (bucket[str[j].id]) {
				printf("%s\n", str[j].name);
			}	
		}
		for (itr = buf[i].begin(); itr != buf[i].end(); ++itr) {
			bucket[*itr] = 0;
		}
	}
    return 0;
}
