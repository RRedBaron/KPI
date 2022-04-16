#include "Worker.h"

Worker::Worker(){} //конструктор по умолчанию

Worker::Worker(string line) {
	int pos = 0;
	for (int i = 0; i < line.size(); i++) {
		if (isdigit(line[i])) {
			pos = i;
			break;
		}
	}
	name = line.substr(0, pos);
    string date = line.substr(pos, line.size());
    birth_day = stoi(split(date, '-')[0]);
    birth_month = stoi(split(date, '-')[1]);
    birth_year = stoi(split(date, '-')[2]);
    age = birth_day + birth_month*30 + birth_year*365;
}

string Worker::GetName() {
    return this->name;
}

void Worker::ShowAgeOnGivenDate(string date) {
    int given_year = stoi(split(date, '-')[2]);
    int given_month = stoi(split(date, '-')[1]);
    int given_day = stoi(split(date, '-')[0]);
    int d_day, d_month, d_year;
    d_year = given_year - this->birth_year;
    if (given_month < this->birth_month) { d_month = given_month + 12 - this->birth_month; }
    else { d_month = given_month - this->birth_month; }
    if (given_day < this->birth_day) { d_day = given_day + 30 - this->birth_day; }
    else { d_day = given_day - this->birth_day; }
    if (given_month < this->birth_month || given_month == this->birth_month && given_day < birth_day) {
        d_year--;
    }
    printf("%d лет %d месяцев %d дней\n", d_year, d_month, d_day);
}

bool operator > (const Worker& a, const Worker& b) {
    return (a.age < b.age);
}

vector<string> split(string line, char sep) {
    vector<string> words;
    string temp_word = "";
    line += sep;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
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