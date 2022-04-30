#include "TDate.h"

TDate::TDate(string line) {
    this->day = stoi(timesplit(line)[0]);
    this->month = stoi(timesplit(line)[1]);
    this->year = stoi(timesplit(line)[2]);
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

void TDate::ShowDate() {
    printf("%d %d %d\n", day, month, year);
}

vector<string> timesplit(string line) {
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

void PrintVector(vector <TDate*> base) {
    for (int i = 0; i < base.size(); i++) {
        base[i]->ShowDate();
    }
}

void TDate1::ShowDate() {
    printf("%d.%d.%d\n", day, month, year);
}

void TDate2::ShowDate() {
    printf("%d-%d-%d\n", day, month, year);
}