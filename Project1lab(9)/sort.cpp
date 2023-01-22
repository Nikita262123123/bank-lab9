#include "sort.h"
#include <cstring>
#include <iostream>

BankOperation** quickSort(BankOperation* array[], int size, int (*check)(BankOperation* element1, BankOperation* element2)) {
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	BankOperation* mid = array[size / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (check(array[i], mid) == -1) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (check(array[i], mid) == 1) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			BankOperation* tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		quickSort(array, j + 1, check);
	}
	if (i < size) {
		//"Првый кусок"
		quickSort(&array[i], size - i, check);
	}

	return array;
}

BankOperation** selectionSort(BankOperation* array[], int size, int (*check)(BankOperation* element1, BankOperation* element2)) {
	int min = 0; // для записи минимального значения
	BankOperation* buf; // для обмена значениями 

	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (check(array[j], array[min]) == -1) {
				min = j;
			}
		}

		if (i != min)
		{
			buf = array[i];
			array[i] = array[min];
			array[min] = buf;
		}
	}

	return array;
}

int sortByAmount(BankOperation* element1, BankOperation* element2) {
	double result = element1->amount - element2->amount;

	if (result < 0) return -1;
	if (result == 0) return 0;
	if (result > 0) return 1;
}

int sortByAccount(BankOperation* element1, BankOperation* element2) {
	return element1->account.compare(element2->account);
}