/*23. Створити клас ТDate, який містить трійку цілих чисел, що представляють чис -
ло, місяць та рік, і методи для порівняння дат, заданих різними форматами, їх збі -
льшення / зменшення на вказану величину.На основі цього класу створити класи -
нащадки TDate1 та TDate2, що представляють дати в форматі "ЧЧ.ММ.РРРР" та
"ЧЧ-MM-РРРР" відповідно.Створити n об'єктів TDate1 та m об'єктів TDate2.
Визначити саму пізню дату, а також дати, що належать заданому періоду дат. */

#include "TDate.h"

int main() {
	vector <TDate*> base;
	int n, m;
	string str;
	cout << "Enter n >> "; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		base.push_back(new TDate1(str));
	}
	cout << "Enter m >> "; cin >> m;
	cin.ignore();
	for (int i = 0; i < m; i++) {
		getline(cin, str);
		base.push_back(new TDate2(str));
	}
	cout << "List of daets in according format:\n";
	TDate* latest = base[0];
	for (int i = 0; i < m + n; i++) {
		base[i]->ShowDate();
		if (base[i]->CompareDates(*latest)) {
			latest = base[i];
		}
	}
	cout << "The latest date: ";
	latest->ShowDate();
	string date1, date2;
	cout << "Enter the lower limit: ";
	getline(cin, date1);
	cout << "Enter the upper limit: ";
	getline(cin, date2);
	cout << "Dates that suit the given range:\n";
	for (int i = 0; i < m + n; i++) {
		if (base[i]->IsInTimeInterval(date1, date2)) {
			base[i]->ShowDate();
		}
	}
}