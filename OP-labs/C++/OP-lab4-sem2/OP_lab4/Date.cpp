#include "Date.h"

Date::Date(int day, int month, int year) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(string line) {
    vector <string> tmp = split(line);
    this->year = stoi(tmp[2]);
    this->month = stoi(tmp[1]);
    this->day = stoi(tmp[0]);
}

Date::Date(Date& a) {
    this->day = a.day;
    this->month = a.month;
    this->year = a.year;
}

int Date::GetDay() { return this->day; }
int Date::GetMonth() { return this->month; }
int Date::GetYear() { return this->year; }

int Date::DaysBeforeNextYear() {
    int days[12] = { 365, 334, 304, 273, 243, 212, 181, 151, 120, 90, 59, 31};
    return days[this->month - 1] - this->day;
}

Date& Date::operator++() {
    month++;
    if (month > 12) {
        year++;
        month = 1;
    }
    return *this;
}

Date& Date::operator++(int) {
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    day++;
    if (day > days[month - 1]) {
        month++;
        day = 1;
    }
    if (month > 12) {
        year++;
        month = 1;
    }
    return *this;
}

bool operator>(Date& a, Date& b) {
    return (a.year * 365 + a.month * 30 + a.day) > (b.year * 365 + b.month * 30 + b.day);
}

vector<string> split(string line) {
    vector<string> words;
    char sep[4] = { ' ', ':', '-', '.' };
    string temp_word = "";
    line += ' ';
    for (int i = 0; i < line.length(); i++) {
        char* symbol = find(begin(sep), end(sep), line[i]);
        if (symbol != end(sep)) {
            if (temp_word.length() > 0) {
                words.push_back(temp_word);
            }
            temp_word = "";
        }
        else {
            temp_word += line[i];
        }
    }
    return words;
}

