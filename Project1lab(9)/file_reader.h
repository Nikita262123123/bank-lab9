#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "bank_operations.h"

void read(const char* file_name, book_subscription* array[], int& size);

#endif