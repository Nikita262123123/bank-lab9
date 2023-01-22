#include <iostream>

using namespace std;

#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"

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
        for (int i = 0; i < size; i++)
        {
            cout << operations[i]->date.day << '.';
            cout << operations[i]->date.month << '.';
            cout << operations[i]->date.year << endl;

            cout << operations[i]->time.hours << ':';
            cout << operations[i]->time.minutes << ':';
            cout << operations[i]->time.seconds << endl;
            cout << operations[i]->type <<  endl;
            cout << operations[i]->account << endl;
            cout << operations[i]->amount << endl;
            cout << operations[i]->description << endl;
            
            cout << '\n';
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


/* #include <iostream>
#include "stukt.h"
#include "reader.h"
#include <iostream>
#include <algorithm>
#include "Header.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    Data data[5];
    for (int i = 0; i < 5; i++)
        data[i] = isertData();
    cout << "0-Vyvesti vse bankovskie prihodnye operacii. 1-Vyvesti vse bankovskie operacii za noyabr' 2021 goda." << endl;
    int a;
    cin >> a;
    if (a == 0) {
        sort1(data);
    }
    else if (a == 1) {
        sort2(data);
    }
    bool (*comp[])(Data, Data) = { *comp1, *comp2 };
    cout << "0-sortirovka vyborom 1-bystraya" << endl;
    cin >> a;
    int t;
    cout << "0-Po vozrastaniyu naznacheniya platezha 1-Po vozrastaniyu nomera schyota, a v ramkah odnogo schyota po vozrastaniyu vida operacii, a v ramkah odnogo vida operacii po ubyvaniyu summy operacii" << endl;
    cin >> t;
    if (a == 0) {
        choicesSort(data, 5, comp[t]);
    }
    showall(data);
} */
