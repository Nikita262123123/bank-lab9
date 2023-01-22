#include "sort.h"
#include <cstring>
#include <iostream>

BankOperation** quickSort(BankOperation* array[], int size, int (*check)(BankOperation* element1, BankOperation* element2)) {
	//��������� � ������ � � ����� �������
	int i = 0;
	int j = size - 1;

	//����������� ������� �������
	BankOperation* mid = array[size / 2];

	//����� ������
	do {
		//��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
		//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (check(array[i], mid) == -1) {
			i++;
		}
		//� ������ ����� ���������� ��������, ������� ������ ������������
		while (check(array[i], mid) == 1) {
			j--;
		}

		//������ �������� �������
		if (i <= j) {
			BankOperation* tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//����������� ������, ���� ��������, ��� �����������
	if (j > 0) {
		//"����� �����"
		quickSort(array, j + 1, check);
	}
	if (i < size) {
		//"����� �����"
		quickSort(&array[i], size - i, check);
	}

	return array;
}

BankOperation** selectionSort(BankOperation* array[], int size, int (*check)(BankOperation* element1, BankOperation* element2)) {
	int min = 0; // ��� ������ ������������ ��������
	BankOperation* buf; // ��� ������ ���������� 

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