#include "TDate.h"

TDate::TDate() {
    this->day = 1;
    this->month = 1;
    this->year = 1970;
}

TDate::TDate(string line) {
    regex regular("([\\d]{1,2})[- /:;.,_]([\\d]{1,2})[- /:;.,_]([\\d]{0,4})");
    cmatch result;
    while (!regex_match(line.c_str(), result, regular) || !IsDateValid(result)) {
        cerr << "Wrong date format. Try again: ";
        getline(cin, line);
    }
    day = stoi(result[1]);
    month = stoi(result[2]);
    year = stoi(result[3]);
}

int TDate::GetDays() {
    return (this->year * 365 + this->month * 30 + this->day);
}

void TDate::IncreaseDate(int day, int month, int year) {
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (day > 0) {
        this->day++;
        if (this->day > days[this->month - 1]) {
            this->month++;
            if (this->month > 12) {
                this->year++;
                this->month = 1;
            }
            this->day = 1;
        }
        day--;
    }
    while (month > 0) {
        this->month++;
        if (this->month > 12) {
            this->month = 1;
            this->year++;
        }
        month--;
    }
    this->year += year;
}

void TDate::DecreaseDate(int day, int month, int year) {
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (day > 0) {
        this->day--;
        if (this->day == 0) {
            this->month--;
            if (this->month == 0) {
                this->month = 12;
                this->year--;
                
            }
            this->day = days[this->month - 1];
        }
        day--;
    }
    while (month > 0) {
        this->month--;
        if (this->month == 0) {
            this->year--;
            this->month = 12;
        }
        month--;
    }
    this->year -= year;
}

bool TDate::CompareDates(TDate& other) {
    if (this->GetDays() > other.GetDays()) {
        return true;
    }
    else {
        return false;
    }
}

bool TDate::IsInTimeInterval(string date1, string date2) {
    TDate lower_date = TDate(date1);
    TDate upper_date = TDate(date2);
    int lower = lower_date.GetDays();
    int upper = upper_date.GetDays();
    return (this->GetDays() >= lower && this->GetDays() <= upper);
}

bool IsDateValid(cmatch date) {
    int day = stoi(date[1]);
    int month = stoi(date[2]);
    int year = stoi(date[3]);
    if ((year % 4 == 0) && (month == 2) && (day > 29) || (year % 4 != 0) && (month == 2) && (day > 28)) {
        return false;
    }
    if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30)) {
        return false;
    }
    if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || 
        (month == 10) || (month == 12)) && (day > 31)) {
        return false;
    }
    if (month > 12 || month < 1) return false;
    return true;
}

void TDate::ShowDate() {
    printf("%d %d %d\n", day, month, year);
}

void PrintVector(vector <TDate*> base) {
    for (auto& s : base) {
        s->ShowDate();
    }
}

TDate1::TDate1(string line):TDate(line) {}

TDate2::TDate2(string line):TDate(line){}

void TDate1::ShowDate() {
    printf("%d.%d.%d\n", day, month, year);
}

void TDate2::ShowDate() {
    printf("%d-%d-%d\n", day, month, year);
}