#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int day = 1, int month = 1, int year = 1970);
	Date(string line);
	Date(Date& a);
	int GetYear();
	int GetMonth();
	int GetDay();
	int DaysBeforeNextYear();
	Date& operator++ ();
	Date& operator++ (int);
	friend bool operator> (Date& a, Date& b);
};

vector<string> split(string line);