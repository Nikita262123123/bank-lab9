#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <string>

using namespace std;

Date convertDate(char* str) {
    Date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);

    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);

    return result;
}

Time convertTime(char* str) {
    Time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);

    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minutes = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.seconds = atoi(str_number);

    return result;
}

void read(const char* file_name, BankOperation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            BankOperation* item = new BankOperation;
            file >> tmp_buffer;
            item->date = convertDate(tmp_buffer);

            file >> tmp_buffer;
            item->time = convertTime(tmp_buffer);

            file >> item->type;
            file >> item->account;

            file >> tmp_buffer;
            item->amount = stod(tmp_buffer);

            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(tmp_buffer, MAX_STRING_SIZE);
            item->description = string(tmp_buffer);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}