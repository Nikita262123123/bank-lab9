#pragma once
#pragma once
#ifndef SORT_H
#define SORT_H

#include "bank_operations.h"

BankOperation** quickSort(BankOperation* array[], int size, int (*check)(BankOperation* element1, BankOperation* element2));
BankOperation** selectionSort(BankOperation* array[], int size, int (*check)(BankOperation* element1, BankOperation* element2));


int sortByAmount(BankOperation* element1, BankOperation* element2);

int sortByAccount(BankOperation* element1, BankOperation* element2);

#endif
