#include <stdio.h>
#include <string.h>

char s1[100005], s2[100005];
char buffer[1000000];
char buf[50000], counter = 0;

void cycle() {
	int len1 = strlen(s1), len2 = strlen(s2);
	if (len1 != len2) {
		printf("NO\n");
		counter += 3;
	} else {
		bool flag = false;
		for (int i = 0; i < len1; i++) {
			int j, cur;
			for (j = 0, cur = i; j < len1 && s1[cur] == s2[j]; j++, cur = (cur+1) % len1);
			if (j == len1) {
				flag = true;
				printf("YES\n");
				counter += 4;
				break;
			}
		}
		if (!flag) {
			printf("NO\n");
			counter += 3;
		}
	}
}

int main() {
	while(scanf("%s", s1) != EOF) {
		scanf("%s", s2);
		cycle();
	}
	return 0;
}