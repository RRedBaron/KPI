#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Worker {
private:
	string name;
	int birth_day, birth_month, birth_year;
public:
	Worker();
	Worker(string line);
	void ShowAgeOnGivenDate(string date);
	int FindAge();
	string GetName();
};

vector<string> split(string line, char sep = ' ');