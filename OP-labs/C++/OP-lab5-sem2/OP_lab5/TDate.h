#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class TDate
{
protected:
	int day;
	int month;
	int year;
public:
	TDate();
	TDate(string);
	int GetDays();
	void IncreaseDate(int day = 0, int month = 0, int year = 0);
	void DecreaseDate(int day = 0, int month = 0, int year = 0);
	bool IsInTimeInterval(string, string);
	bool CompareDates(TDate&);
	virtual void ShowDate();
};

class TDate1 : public TDate {
public:
	TDate1(string);
	void ShowDate() override;
};

class TDate2 : public TDate {
public:
	TDate2(string);
	void ShowDate() override;
};

bool IsDateValid(cmatch);