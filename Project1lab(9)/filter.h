#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "bank_operations.h"

BankOperation** filter(BankOperation* array[], int size, bool (*check)(BankOperation* element), int& result_size);

bool checkIncomeOperation(BankOperation* element);

bool checkOperationDate(BankOperation* element);


#endif
