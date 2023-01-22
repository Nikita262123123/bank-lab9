
#include <iostream>
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
}
