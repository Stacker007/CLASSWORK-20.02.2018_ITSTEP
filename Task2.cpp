

#include <iostream>
#include <ctime>
#define SIZE 10

using namespace std;
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int myArr[SIZE] = {};
	randArr(myArr, SIZE);
	printArr(myArr, SIZE);
	cout << endl << endl;
	int sizeAfter = SIZE;
	int *tmpPTR = myArr;

	while (tmpPTR < myArr + sizeAfter)
	{
		bool flag = true;
		for (int i = 2; i < *tmpPTR; i++) {
			if (*tmpPTR % i == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int *delPTR;
			delPTR = tmpPTR;
			sizeAfter--;
			while (delPTR < myArr + sizeAfter) {
				*delPTR = *(delPTR + 1);
				delPTR++;
			}

		}
		tmpPTR++;
	}
	printArr(myArr, sizeAfter);
	cout << endl << endl;
	system("pause");
}



void randArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		*a = rand() % 50 + 1;
}

void printArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		printf("%3d ", *a);
}
