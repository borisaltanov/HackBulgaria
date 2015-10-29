#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <direct.h>
using namespace std;

//removing unnecessary symbols
bool isJunk(char);

//making the first latter of a string capital
string firstCapitalLetter(string);

//checking for substring in a string
bool occurence(string, string);

//returning the index of the first letter of a substring
int occurenceIndex(string, string);

//reading file
string readFile(string);

//getting keys and values from all_packages
string getKeysAndValues(string);

//getting dependencies' keys
vector<string> getDependencies(string);

//installing packages from all_packages
void installALLPACK(string, string);

//main installing function
void instalation(string);

int main() {
	string directory;
	cout << "Enter directory: ";
	cin >> directory;
	instalation(directory);

	return 0;
}

bool isJunk(char s) {
	switch (s) {
	case '{': case '}':
	case '[': case ']':
	case ':': case ' ':
	case '"':
		return false;
		break;
	default:
		return true;
		break;
	}
}

string firstCapitalLetter(string s) {
	if (s[0] >= 'a' && s[0] <= 'z') {
		s[0] -= 32;
	}
	return s;
}

bool occurence(string subStr, string mainStr) {
	size_t found = mainStr.find(subStr);
	if (found != std::string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int occurenceIndex(string subStr, string mainStr) {
	size_t found = mainStr.find(subStr);
	if (found != std::string::npos) {
		return found;
	}
	else {
		return -1;
	}
}

string readFile(string dir) {
	ifstream myfile(dir);
	string result = "";
	string line = "";
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			result += line;
			result += '\n';
		}
		myfile.close();
	}
	return result;
}

string getKeysAndValues(string dir) {
	string temp = readFile(dir);
	string result = "";
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == ':') {
			result += "KEY";
		}
		else if (temp[i] == '['){
			if (temp[i + 1] == ']' && temp[i + 2] == ','){
				i += 2;
			}
			else if (temp[i + 1] == ']') {
				i++;
			}
		}
		else if (temp[i] == ']' && temp[i + 1] == ',') {
			result += "VAL";
			i++;
		}
		else if (temp[i] == ',') {
			result += "VAL";
		}
		else if (isJunk(temp[i])) {
			result += temp[i];
		}
	}
	return result;

}

vector<string> getDependencies(string dir) {
	string dependecies = dir + "\\dependencies.json";
	string temp = readFile(dependecies);
	string tempDEP = "";
	vector<string> result;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == '[') {
			int j = i;
			while (temp[j] != ']') {
				if (temp[j] == ','){
					result.push_back(tempDEP);
					tempDEP.clear();
				}
				else if (isJunk(temp[j])){
					tempDEP += temp[j];
				}
				j++;
			}
			result.push_back(tempDEP);
		}
	}
	return result;
}

void installALLPACK(string key, string dir) {
	vector <string> tempVal;
	string all_packages = dir + "\\all_packages.json";
	string allKeys = getKeysAndValues(all_packages);
	string installedModules = dir + "\\installed_modules\\";
	string tempKey = key + "KEY";
	if (occurence(tempKey, allKeys)) {
		string tempModule = installedModules + key;
		if (_mkdir(tempModule.c_str()) == -1){
			cout << firstCapitalLetter(key) << " is already installed" << endl;
			return;
		}
		tempModule.clear();
		cout << "Instaling " << key << "..." << endl;
		int i = (occurenceIndex(tempKey, allKeys) + tempKey.size());
		if (allKeys[i] != '\n') {
			cout << "In order to install " << key << " we need ";
			int i = (occurenceIndex(tempKey, allKeys) + tempKey.size());
			string tempValues = "";
			while (allKeys[i] != '\n'){
				if (allKeys[i] == 'V' && allKeys[i + 1] == 'A' && allKeys[i + 2] == 'L'){
					if (allKeys[i + 3] == '\n') {
						cout << '.' << endl;
						i += 3;
					}
					else {
						cout << ", ";
						i += 3;
					}
					tempVal.push_back(tempValues);
					tempValues.clear();
				}
				else {
					tempValues += allKeys[i];
					cout << allKeys[i];
					i++;
				}
			}
			for (int k = 0; k < tempVal.size(); k++){
				installALLPACK(tempVal[k], dir);
			}
			tempVal.clear();
		}
	}
	else {
		cout << "No key for " << key << '.' << endl;
	}
}

void instalation(string directory) {
	getDependencies(directory);
	for (int i = 0; i < getDependencies(directory).size(); i++) {
		installALLPACK(getDependencies(directory).at(i), directory);
	}
	cout << "All done" << endl;

}