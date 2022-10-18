//****************************************
//*程 序：HelloForU.cpp                  *
//*时 间：2013-2-25                      *
//*作 者：ytm                            *
//*功 能：编程题库/浙江大学-机试/2012 第 *
//*       一题                           *
//****************************************

#include <stdio.h>
#include <string.h>

int main() {
	char str[100] = {0};    //存储输入字符串的变量  
	unsigned int side, bottom, len;  //"U"两侧及底部的长度，字符串的长度
	unsigned int i, j;

	gets(str);
	len = strlen(str);
	side = (len + 2) / 3 - 1;
	bottom = len - 2 * side;

	for(i = 0; i < side; i++) {
		putchar(str[i]);
		for(j = 1; j <= bottom - 2; j++) {
			putchar(' ');
		}
		putchar(str[len-i-1]);
		putchar('\n');
	}
	for(i = side + 1; i <= side + bottom; i++) {
		putchar(str[i - 1]);
	}
	return 0;
}
