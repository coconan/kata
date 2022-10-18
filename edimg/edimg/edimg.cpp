#include <cstdio>
#include <cstdlib>

char buffer[512];

int main(void) {
	FILE *src, *dst;
	src = fopen("src", "r");
	dst = fopen("test.img", "ab");
	if (src==NULL) {
		printf("fuck");
	}
	fread(buffer, sizeof(char), sizeof(buffer), src);
	fwrite(buffer, sizeof(char), sizeof(buffer), dst);
	
	fclose(src);
	fclose(dst);
}