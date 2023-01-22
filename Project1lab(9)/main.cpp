#include <iostream>

using namespace std;

#include "bank_operations.h"
#include "file_reader.h"
#include "filter.h"
#include "sort.h"
#include "constants.h"

void output(BankOperation* operations)
{
	cout << operations->date.day << '.'
		<< operations->date.month << '.'
		<< operations->date.year << "    "

		<< operations->time.hours << ':'
		<< operations->time.minutes << ':'
		<< operations->time.seconds << "    "
		<< operations->type << "    "
		<< operations->account << "    "
		<< operations->amount << "    "
		<< operations->description << endl << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #9. GIT\n";
    cout << "Вариант #7. Банковские операции\n";
    cout << "Автор: Лабуть Никита\n\n";

	BankOperation* operations[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", operations, size);
		cout << "*****   *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(operations[i]);
		}
		bool (*check_function)(BankOperation*) = NULL; // check_function - какую функцию фильтрации выберет пользователь
		int (*sort_option_function)(BankOperation*, BankOperation*) = NULL; // check_function - какой критерий сортировки выберет пользователь
		BankOperation** (*sort_function)(BankOperation*[], int, int (*check)(BankOperation * element1, BankOperation * element2)) = NULL; // check_function - какой метод сортировки выберет пользователь

		cout << "1) Вывести приходные операции\n";
		cout << "2) Вывести операции за ноябрь 2021 года\n";
		cout << "3) Сортировка\n\n";

		int choise;
		cin >> choise;
		cout << endl;

		switch (choise)
		{
		case 1:
			check_function = checkIncomeOperation;   
			cout << "*****Все приходные операции*****\n\n";
			break;
		case 2:
			check_function = checkOperationDate;      
			cout << "*****Все операции за ноябрь 2021*****\n\n";
			break;
		case 3:
		{
			int sortChoise;
			cout << "Выберите метод сортировки: " << endl;
			cout << "1) Быстрая сортировка" << endl;
			cout << "2) Сортировка выбором" << endl;
			cin >> sortChoise;

			switch (sortChoise)
			{
			case 1:
				sort_function = quickSort;
			case 2:
				sort_function = selectionSort;
			}
			
			int sortOptionChoise;
			cout << "Выберите критерий сортировки: " << endl;
			cout << "1) Сортировка по сумме операции" << endl;
			cout << "2) Сортировка по номеру счета" << endl;
			cin >> sortOptionChoise;

			switch (sortOptionChoise)
			{
			case 1:
				sort_option_function = sortByAmount;
			case 2:
				sort_option_function = sortByAccount;
			}
			break;
		}
		default:
			throw "  ";
		}

		if (check_function)
		{
			int new_size;
			BankOperation** filtered = filter(operations, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}

		if (sort_function && sort_option_function) {

			BankOperation** sorted = sort_function(operations, size, sort_option_function);

			for (int i = 0; i < size; i++)
			{
				output(sorted[i]);
			}
			delete[] sorted;
		}

		for (int i = 0; i < size; i++)
		{
			delete operations[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;

}
