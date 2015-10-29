#include "TABLE.HPP"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string);
//counting occurences of a substring
int countOccurence(string, string);
//making the table a string horizontally from left to right
string HorizontalL2R(Table);
//making the table a string vertically from first to last row
string VerticalF2L(Table);
//making the table a string diagonally from (0,n) to (n,0)
string DiagonalR2L(Table);
//making the table a string diagonally from (0,0) to (n,n)
string DiagonalL2R(Table);
//counting occurences of a word in a table
int countWord(string, Table);

int main() {
	int rows = 0, cols = 0;
	string word = "";
	while (rows <= 0) {
		cout << "Enter rows: ";
		cin >> rows;
	}
	while (cols <= 0) {
		cout << "Enter cols: ";
		cin >> cols;
	}
	Table table(rows, cols);
	cout << "Fill your table: " << endl;
	table.fill();
	cout << endl << "Enter the word you are searching: ";
	cin >> word;
	cout << "-----------------------" << endl;
	cout << "Here is your table: " << endl;
	table.print();
	cout << "The occurences of the word in the table are: " 
		<< countWord(word, table) << endl;

	system("pause");
	return 0;

}


bool isPalindrome(string word) {
	for (int i = 0; i < word.size(); ++i) {
		if (word[i] != word[word.size() - 1 - i]) {
			return false;
			break;
		}
	}
	return true;
}

int countOccurence(string mainStr, string subStr) {
	int count = 0;
	size_t nPos = mainStr.find(subStr, 0);
	while (nPos != string::npos)
	{
		count++;
		nPos = mainStr.find(subStr, nPos + 1);
	}
	return count;
}

string HorizontalL2R(Table testTable) {
	string result = "";
	for (int i = 0; i < testTable.getRows(); i++) {
		for (int j = 0; j < testTable.getCols(); j++) {
			result += testTable.getData(i, j);
		}
		result += '|';
	}
	return result;
}

string VerticalF2L(Table testTable) {
	string result = "";
	for (int j = 0; j < testTable.getCols(); j++) {
		for (int i = 0; i < testTable.getRows(); i++) {
			result += testTable.getData(i, j);
		}
		result += '|';
	}
	return result;
}

string DiagonalR2L(Table testTable) {
	string result = "";
	int k, i, j;
	for (k = -testTable.getCols() + 1; k <= (min(testTable.getCols(), testTable.getRows()) - 1); k++)
	{
		for (i = 0; i < testTable.getRows(); i++)
		{
			for (j = testTable.getCols() - 1; j >= 0; j--)
			{
				if ((i - j) == k)
				{
					result += testTable.getData(i, j);
				}

			}
		}
		result += '|';
	}
	return result;
}

string DiagonalL2R(Table testTable) {
	string result = "";
	int k, i, j;
	for (k = 0; k <= (testTable.getRows() + testTable.getCols() - 2); k++)
	{
		for (i = 0; i < testTable.getRows(); i++)
		{
			for (j = testTable.getCols() - 1; j >= 0; j--)
			{
				if ((i + j) == k)
				{
					result += testTable.getData(i, j);
				}

			}
		}
		result += '|';
	}
	return result;
}

int countWord(string word, Table testTable) {
	int counter = 0;
	string temp = "";
	
	temp = HorizontalL2R(testTable);
	counter += countOccurence(temp, word);
	if (!isPalindrome(word)){
		reverse(temp.begin(), temp.end());
		counter += countOccurence(temp, word);
	}
	temp.clear();

	temp = VerticalF2L(testTable);
	counter += countOccurence(temp, word);
	if (!isPalindrome(word)){
		reverse(temp.begin(), temp.end());
		counter += countOccurence(temp, word);
	}
	temp.clear();

	temp = DiagonalR2L(testTable);
	counter += countOccurence(temp, word);
	if (!isPalindrome(word)){
		reverse(temp.begin(), temp.end());
		counter += countOccurence(temp, word);
	}
	temp.clear();

	temp = DiagonalL2R(testTable);
	counter += countOccurence(temp, word);
	if (!isPalindrome(word)){
		reverse(temp.begin(), temp.end());
		counter += countOccurence(temp, word);
	}
	temp.clear();
	
	cout << temp << endl;

	return counter;
}