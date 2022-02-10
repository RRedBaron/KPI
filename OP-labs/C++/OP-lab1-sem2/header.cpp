#include "Header.h"

void CreateTextFile(string filename, int& rows) {
	ofstream inf(filename);
	vector <string> text;
	string str = "";
	do {
		std::getline(std::cin, str);
		if (str.size() > 0) {
			text.push_back(str + '\n');
			rows++;
		}
	} while (str != "");
	for (auto s : text) {
		inf << s;
	}
	inf.close();
}

void CreateFileWithSimilarRows(string filename, const int& rows1, const int& rows2, int& count) {
	ifstream ouf1("mytext.txt");
	ifstream ouf2("mytext2.txt");
	ofstream inf(filename);
	string str1, str2;
	for (size_t i = 0; i < rows1; i++)
	{
		getline(ouf1, str1);
		for (size_t j = 0; j < rows2; j++)
		{
			getline(ouf2, str2);
			if (str1 == str2) {
				inf << str1 << '\n';
				count++;
			}
		}
		ouf2.seekg(0, ios::beg);
	}
	ouf1.close();
	ouf2.close();
	inf.close();
}

void PrintFile(string filename) {
	ifstream ouf(filename);
	string str;
	cout << filename << ":\n";
	while (!ouf.eof()) {
		getline(ouf, str);
		cout << str << '\n';
	}
	ouf.close();
}