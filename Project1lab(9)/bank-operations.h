#pragma once
#ifndef BANK_OPERATION_H
#define BANK_OPERATION_H

#include <string>
#include "constants.h"

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

struct BankOperations
{
    Date date;
    Time time;
    string type;
    string account;
    double amount;
    string description;
};

#endif