#include <iostream>
#include "stukt.h"
#include "reader.h"
#include <iostream>
#include <algorithm>
#include "Header.h"
using namespace std;
void sort1(Data* data)
{
    for (int i = 0; i < 5; i++)
    {
        if (data[i].type == "prihod")
        {
            show(data[i]);
        }
    }
}
void sort2(Data* data)
{
    for (int i = 0; i < 5; i++)
    {
        if (data[i].data[3] == '1' && data[i].data[4] == '1' && data[i].data[6] == '2' && data[i].data[7] == '1')
        {
            show(data[i]);
        }
    }
}
void choicesSort(Data* arrayPtr, int length_array, bool comp(Data a, Data b)){
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        auto temp = arrayPtr[0]; 
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (!comp(arrayPtr[repeat_counter], arrayPtr[element_counter]))
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
            }
        }
    }
}
bool comp1(Data a, Data b) {
    return a.nazn > b.nazn;
}
bool comp2(Data a, Data b) {
    if (a.blank == b.blank) {
        if (a.type == b.type) {
            return a.sum < b.sum;
        }
        else return a.type > b.type;

    }
    else return a.blank > b.blank;
}
void showall(Data* data) {
    for (int i = 0; i < 5;i++)
        show(data[i]);
}
