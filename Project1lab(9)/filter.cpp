#include "filter.h"
#include <cstring>
#include <iostream>

BankOperation** filter(BankOperation* array[], int size, bool (*check)(BankOperation* element), int& result_size) {
	BankOperation** result = new BankOperation * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}

	return result;
}

bool checkIncomeOperation(BankOperation* element) {
	return element->type == "приход";
}

bool checkOperationDate(BankOperation* element) {
	return element->date.month == 11 && element->date.year == 21;
}
