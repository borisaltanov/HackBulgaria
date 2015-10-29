#include "TABLE.HPP"
#include <iostream>
#include <iomanip>
using namespace std;



Table::Table(int _rows = 0, int _cols = 0) {
	rows = _rows;
	cols = _cols;
	data.resize(rows, vector<char>(cols, 0));
}

Table::~Table(){
}

char Table::getData(int i, int j) {
	return data[i][j];
}

int Table::getRows()const {
	return rows;
}
int Table::getCols()const {
	return cols;
}

void Table::fill() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cin >> data[i][j];
	}
}

void Table::print() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << setw(2) << data[i][j];
		}
		cout << endl;
	}
	cout << endl;
}