#pragma once
#ifndef reader
#define reader
#include <fstream>
#include <iostream>
#include "stukt.h"
using namespace std;
ifstream in("data.txt");
Data isertData() {
	Data data;
	in >> data.time;
	in >> data.type;
		in >> data.blank;
		in >> data.sum;
		getline(in, data.nazn);
		return data;
}
void show(Data data) {
	cout << data.data << " " << data.sum << " " << data.nazn << endl;
}

#endif