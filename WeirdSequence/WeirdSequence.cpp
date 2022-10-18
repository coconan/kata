//********************************************
//*程序：WeirdSequence.cpp                   *
//*作者：ytm                                 *
//*时间：2013-1-20 (修改：2013-2-4)          *               
//*功能：生成任意长度的，元素的因子只为2、   *
//*      3、5的数列                          *
//********************************************

#include <iostream>
#include <cstdlib>

using namespace std;

int BinarySearch(long * array, int left, int right, long num);

int main()
{
	int length;
	cin>>length;

	long * array, * array1;
	array = (long *)malloc((length + 1) * sizeof(long));
	array1 = (long *)malloc((length / 2) * sizeof(long));

	/*
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	int counter = 4;
	*/

	int i = 0, j = 0, counter = 0, counter1 = 0;
	long next2 = 2, next3 = 3, next5 = 5;
	for(;counter < length;)
	{
		/*
		if(((i % 2 == 0) && BinarySearch(array, 1, counter, i / 2)) ||
		   ((i % 3 == 0) && BinarySearch(array, 1, counter, i / 3)) ||
		   ((i % 5 == 0) && BinarySearch(array, 1, counter, i / 5)))
		*/
		/*
		int temp = i;
		while(temp % 5 == 0) temp = temp / 5;
		while(temp % 3 == 0) temp = temp / 3;
		while(temp % 2 == 0) temp = temp / 2;
		if(temp == 1)
		*/
		if (next2 < next3 && next2 < next5) {
			counter++;
			array[counter] = next2;
			i++;
			next2 = array[i] * 2;
		} else if (next3 < next5 && next3 < next2) {
			counter++;
			counter1++;
			array[counter] = next3;
			array1[counter1] = next3;
			j++;
			next3 = array1[j] * 3;
		} else if (next5 < next2 && next5 < next3) {
			counter++;
			counter1++;
			array[counter] = next5;
			array1[counter1] = next5;
			next5 = next5 * 5;
		}
			
	}
/*
	for(i = 1; i <= length; i++)
	{
		cout<<array[i]<<endl;
	}
	*/
	cout << array[length] << endl;
	return 0;
}

/*
int BinarySearch(long * array, int left, int right, long num)
{
	while(right >= left)
	{
		int mid = left + (right - left) / 2;
		if(array[mid] > num)
			right = mid - 1;
		else if(array[mid] < num)
			left = mid + 1;
		else if(array[mid] == num)
			return 1;
	}

	return 0;
}
*/