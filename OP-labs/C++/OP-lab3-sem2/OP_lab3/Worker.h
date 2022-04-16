#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Worker {
private:
	string name;
	int birth_day, birth_month, birth_year, age;
public:
	Worker();
	Worker(string line);
	void ShowAgeOnGivenDate(string date);
	friend bool operator> (const Worker& a, const Worker& b);
	string GetName();
};

vector<string> split(string line, char sep = ' ');