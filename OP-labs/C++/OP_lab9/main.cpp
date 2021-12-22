#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	cout << "Enter your string: ";
	string str, currentword = ""; getline(cin, str);
	str += ' ';
	string* stringarray = new string[str.size()];
	size_t i = 0;
	for (auto s : str) {
		if (s != ' ') {
			currentword += s;
		}
		else {
			stringarray[i] = currentword;
			currentword = "";
			i++;
		}
	}
	int maxwordlen = 0, indexofmaxword,
		minwordlen = str.size(), indexofminword;
	string maxword, minword;
	for (int j = 0; j < i; j++) {
		if (stringarray[j].size() > maxwordlen) {
			indexofmaxword = j;
			maxwordlen = stringarray[j].size();
			maxword = stringarray[j];
		}
		if (stringarray[j].size() < minwordlen) {
			indexofminword = j;
			minwordlen = stringarray[j].size();
			minword = stringarray[j];
		}
	}
	for (int j = 0; j < i; j++) {
		if (stringarray[j] == minword) {
			cout << maxword << ' ';
		}
		else if (stringarray[j] == maxword) {
			cout << minword << ' ';
		}
		else {
			cout << stringarray[j] << ' ';
		}
	}
	return 0;
}