#include <iostream>
#include <cstring>

using namespace std;

void sstrrev(char * str) {
	int len = strlen(str);
	for (int i = 0; i < len/2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len-i-1] = temp;
	}
}

class BigInteger {
private:
	char blk[310];
	int len;
public:
	BigInteger(const char * buffer) {
		len = strlen(buffer);
		strcpy(blk, buffer);
	}

	BigInteger(const BigInteger & other) {
		strcpy(blk, other.blk);
		len = other.len;
	}


	BigInteger & operator = (const BigInteger & rhs) { 
		strcpy(blk, rhs.blk); 
		len = rhs.len; 
		return * this;
	}
	BigInteger & operator + (const BigInteger & rhs);
	BigInteger & operator - (const BigInteger & rhs);
	BigInteger operator * (const BigInteger & rhs);
	BigInteger operator / (const BigInteger & rhs);
	BigInteger & leftShift(int n);

	const char * getValue() {
		return blk;
	}
};

BigInteger & BigInteger::operator + (const BigInteger & rhs) {
	int carry = 0, i, commonLen;
	char temp[210];

	if (len < rhs.len) { 
		strcpy(temp, blk);
		strcpy(blk, rhs.blk);
		commonLen = len;
		len = rhs.len;
	} else {
		strcpy(temp, rhs.blk);
		commonLen = rhs.len;
	}
	
	sstrrev(blk);
	sstrrev(temp);

	for (i = 0; i < commonLen; i++) {
		int value = blk[i] + temp[i] - 2 * '0' + carry;
		blk[i] = value % 10 + '0';
		carry = value / 10;
	}

	while (carry && i < len) {
		int value = blk[i] - '0' + carry;
		blk[i] = value % 10 + '0';
		carry = value / 10;
		i++;
	}
	
	if (carry) { 
		blk[i] = carry + '0';
		blk[i+1] = '\0';
		len++;
	}
	sstrrev(blk);

	return * this;
}

BigInteger & BigInteger::operator - (const BigInteger & rhs) {
	bool isPositive, isEqual = false; 
    int commonLen, borrow = 0, i;
	char temp[210];
	if (len == rhs.len) {
		if (strcmp(blk, rhs.blk) > 0) {
			isPositive = true;
		} else if (strcmp(blk, rhs.blk) < 0) {
			isPositive = false;
		} else {
			isEqual = true;
		}
		commonLen = len;
	} else if (len > rhs.len) {
		isPositive = true;
		commonLen = rhs.len;
	} else {
		isPositive = false;
		commonLen = len;
	}

	if (isEqual) { 
		blk[0] = '0';
		blk[1] = '\0';
		return * this;
	}

	if (!isPositive) {
		strcpy(temp, blk);
		strcpy(blk, rhs.blk);
		len = rhs.len;
	} else {
		strcpy(temp, rhs.blk);
	}

	sstrrev(blk);
	sstrrev(temp);
	for (i = 0; i < commonLen; i++) {
		int value = blk[i] - temp[i] - borrow; 
		blk[i] = value >= 0 ? value + '0': value + 10 + '0'; 
		borrow = value >= 0 ? 0 : 1;
	}

	while (borrow && i < len) {
		int value = blk[i] - borrow - '0';
		blk[i] = value >= 0 ? value + '0' : value + 10 + '0';
		borrow = value >= 0 ? 0 : 1;
		i++;
	}
	i = len - 1;
	while (blk[i] == '0' && i > 0) { i--; }
	if (!isPositive) {
		blk[i+1] = '-';
		blk[i+2] = '\0';
	} else {
		blk[i+1] = '\0';
		len = i+1;
	}
	
	sstrrev(blk);
	return * this; 
}

BigInteger & BigInteger::leftShift(int n) {
	for (int i = 0; i < n; i++) {
		blk[len+i] = '0';
	}
	blk[len+n] = '\0';
	len = len + n;
	return * this;
}

BigInteger BigInteger::operator * (const BigInteger & rhs) { 
	BigInteger prod("0");
	char temp[210], rhsCopy[110];
	strcpy(rhsCopy, rhs.blk);
	sstrrev(blk);
	sstrrev(rhsCopy);
	for (int i = 0; i < len; i++) {
		int carry = 0;
		for (int j = 0; j < rhs.len; j++) {
			int value = (blk[i] - '0') * (rhsCopy[j] - '0') + carry;
			temp[j] = value % 10 + '0';
			carry = value / 10;
		}
		if (carry) {
			temp[rhs.len] = carry + '0';
			temp[rhs.len+1] = '\0';
		} else {
			temp[rhs.len] = '\0';
		}
		sstrrev(temp);
		BigInteger t(temp);
		prod + t.leftShift(i);
	}
	return prod; 
}
BigInteger BigInteger::operator / (const BigInteger & rhs) {
	char q[110];
	BigInteger r("");
	if (len < rhs.len) { return BigInteger("0"); }
	if (len == rhs.len && strcmp(blk, rhs.blk) < 0) { return BigInteger("0"); }
	for (int i = 0, j = 0; i < len;) {
		char buffer[110];
		strcpy(buffer, r.blk);
		strncat(buffer, blk+j, 1);
		buffer[r.len+2] = '\0';
		BigInteger temp(buffer);
		int value = 0;
		while (temp.len > rhs.len || (temp.len == rhs.len && strcmp(temp.blk, rhs.blk) >= 0)) {
			value++;
			temp - rhs;
		}
		r = temp; 
		q[j] = value + '0'; i++; j++; 
		q[j+1] = '\0';
	}
	int step = 0;
	for (int i = 0; i < len; i++) {
		if (q[i] != '0') {
			step = i;
			break;
		}
	}
	BigInteger quotient(q+step);
	return quotient; 
}

int main() {
	char buffer[110], op;
	cin >> buffer;
	BigInteger a(buffer);
	cin >> op;
	cin >> buffer;
	BigInteger b(buffer);
	switch (op) {
	case '+': cout << (a + b).getValue() << endl; break;
	case '-': cout << (a - b).getValue() << endl; break;
	case '*': cout << (a * b).getValue() << endl; break;
	case '/': cout << (a / b).getValue() << endl; break;
	}
	return 0;
}