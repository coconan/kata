//****************************************
//*程 序：ZOJ.cpp                        *
//*作 者：ytm                            *
//*时 间：2013-2-26                      *
//*功 能：编程题库/浙江大学-机试/2010 第 *
//*       二题                           *
//****************************************

#include <stdio.h>
#include <string.h>

bool isAC( char str[]) {
	int len = strlen(str);
	char a[1000], b[1000], str1[1000];
	int i = 0, j = 0, k = 0;
	while(str[i] != 'z' && i < len) {
		a[j] = str[i];
		str1[k] = str[i];
		k++;
		i++;
		j++;
	}
	if(i == len) {
		return false;
	}
	a[i] = '\0';
	str1[k++] = 'z';
	i++;
	j = 0;
	while(str[i] != 'j' && i < len) {
		b[j] = str[i];
		str1[k] = str[i];
		k++;
		i++;
		j++;
	}
	if(i == len) {
		return false;
	}
	b[j-1] = '\0';
	if(strlen(b) == 0) {
		return !(bool)strcmp(a, str + 3 + strlen(a));
	}
	i++;
	j = 0;
	str1[--k] = 'j';
	while(j < strlen(a)) {
		if(a[j] == str[i]) {
			i++;
			j++;
		} else {
			return false;
		}
	}
	k++;
	while(i < strlen(str)) {
		str1[k] = str[i];
		i++;
		k++;
	}
	str1[k] = '\0';
	return isAC(str1);

}

int main() {
	char str[1001];
	while( scanf( "%s", str) != EOF) {
		if( isAC( str ) ) {
			printf( "Accepted\n" );
		} else {
			printf( "Wrong Answer\n" );
		}
	}
	return 0;
}