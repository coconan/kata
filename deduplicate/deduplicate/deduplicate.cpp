#include <stdio.h>
#include <string.h>
struct Bucket {
	bool hasDuplicate, isEmpty;
	char s[41];
	Bucket(): hasDuplicate(false), isEmpty(true) {
		s[0] = '\0';
	}
};

Bucket hashTable[1200007];
int duplicates[100000], counter = 0;

size_t hashCode(char s[]) {
	int h = 0;
	for (size_t n = strlen(s), i = 0; i < n; i++) {
		h = (h << 5) | (h >> 27);
		h += (int) s[i];
	}
	return (size_t) h;
}

void put(int n){ //Ë«òÑµãË®
	for (int i = 0; i < n; i++) {
		char tmp[41];
		scanf("%s", tmp);
		size_t hashkey = hashCode(tmp);
		bool flag = false;
		int j = 0, probe = 0, index;
		while (true) {
			index = (hashkey + probe) % 1200007;
			if (hashTable[index].isEmpty) break;
			char *s1 = tmp, *s2 = hashTable[index].s;
			for (; *s1 == *s2 && *s1 != '\0' && *s2 != '\0'; s1++, s2++);
			if (*s1 == '\0' && *s2 == '\0') {
				if (!hashTable[index].hasDuplicate) {
					hashTable[index].hasDuplicate = true;
					duplicates[counter++] = index;
				}
				break;
			} else {
				if (!flag) {
					j++;
					probe = j * j;
					flag = true;
				} else {
					probe = - j * j;
					flag = false;
				}
			}
		}
		if (hashTable[index].isEmpty) {
			hashTable[index].isEmpty = false;
			strcpy(hashTable[index].s, tmp);
		}
	}
}

void printDuplicates() {
	for (int i = 0; i < counter; i++) {
		printf("%s\n", hashTable[duplicates[i]].s);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	put(n);
	printDuplicates();
	return 0;
}