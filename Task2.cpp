

#include <iostream>
#include <ctime>
#define SIZE 15

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
	int *tmpPTR = myArr;
	int *negPTR = myArr + SIZE - 1;
	int *maxPTR = myArr;
	while (tmpPTR < myArr+SIZE)
	{
		if (*tmpPTR >= *maxPTR) maxPTR = tmpPTR;
		tmpPTR++;
	}
	tmpPTR = myArr;
	while (tmpPTR < myArr + SIZE)
	{
		if (*tmpPTR < 0) {
			negPTR = tmpPTR;
			break;
		}
		tmpPTR++;
	}
	cout << "Первый отрицательный элемент: " << *negPTR << endl << "Максимальный элемент (последний): " << *maxPTR << endl;
	negPTR++;
	int i = 0;
	float sum = 0;
	if (negPTR < maxPTR) {
		while (negPTR < maxPTR)
		{
			sum += *negPTR++;
			i++;
		}
		cout << "Среднее арифметическое элементов равно " << sum / i << endl;
	}
	else cout << "Промежуточных элемнетов нет!" << endl;

	
	system("pause");
}



void randArr(int *a, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 21 - 10;
}

void printArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		printf("%3d ", *a);
}
