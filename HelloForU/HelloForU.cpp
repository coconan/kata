//****************************************
//*�� ��HelloForU.cpp                  *
//*ʱ �䣺2013-2-25                      *
//*�� �ߣ�ytm                            *
//*�� �ܣ�������/�㽭��ѧ-����/2012 �� *
//*       һ��                           *
//****************************************

#include <stdio.h>
#include <string.h>

int main() {
	char str[100] = {0};    //�洢�����ַ����ı���  
	unsigned int side, bottom, len;  //"U"���༰�ײ��ĳ��ȣ��ַ����ĳ���
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
