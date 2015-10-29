#ifndef TABLE_HPP
#define TABLE_HPP
#include <vector>
using namespace std;


class Table{
public:
	Table(int, int);
	~Table();

	char getData(int, int);
	int getRows()const;
	int getCols()const;
	void fill();
	void print();
private:
	int rows, cols;
	vector < vector <char> > data;
};

#endif