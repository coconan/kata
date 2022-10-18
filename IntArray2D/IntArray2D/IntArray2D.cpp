#include <iostream>

using namespace std;

class Array2 {
private:
	int nRows, nCols;
	int * pData;

	void deepCopy(const Array2 & that) {
		if (nRows*nCols < that.nRows*that.nCols) {
			delete [] pData;
			pData = new int[that.nRows*that.nCols];
		}

		nRows = that.nRows;
		nCols = that.nCols;

		for (int i = 0; i < nRows*nCols; i++) {
			pData[i] = that.pData[i];
		}
	}

public:
	Array2(): nRows(0), nCols(0), pData(NULL) {}

	Array2(int rows, int cols): nRows(rows), nCols(cols) {
		pData = new int[rows * cols];
	}

	Array2(const Array2 & that) {
		deepCopy(that);
	}

	~Array2() {
		if (pData) { delete [] pData; }
	}
	
	int operator () (int i, int j) {
		return * (pData + i * nRows + j);
	}

	int * const operator [] (int i) {
		return pData + i * nRows;
	}
	
	Array2 & operator = (const Array2 & that) {
		if (pData != that.pData) {
			deepCopy(that);
		}

		return * this;
	} 
};

int main() {
	Array2 a(3,4);
	int i,j;
	for(  i = 0;i < 3; ++i )
		for(  j = 0; j < 4; j ++ )
			a[i][j] = i * 4 + j;
	for(  i = 0;i < 3; ++i ) {
		for(  j = 0; j < 4; j ++ ) {
			cout << a(i,j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b; b = a;
	for(  i = 0;i < 3; ++i ) {
		for(  j = 0; j < 4; j ++ ) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}