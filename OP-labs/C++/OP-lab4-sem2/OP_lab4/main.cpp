#include "Date.h"

int main() {
	setlocale(LC_ALL, "rus");

	cout << "Enter the first date:" << endl;
	int day, month, year;
	cout << "day>> "; cin >> day;
	cout << "month>> "; cin >> month;
	cout << "year>> "; cin >> year;

	Date D1(day, month, year);

	cout << "Enter the second date:" << endl;
	cin.ignore();
	string line; getline(cin, line);
	Date D2(line);

	Date D3(D1);

	printf("D1 %d %d %d\n", D1.GetDay(), D1.GetMonth(), D1.GetYear());
	printf("D2 %d %d %d\n", D2.GetDay(), D2.GetMonth(), D2.GetYear());
	printf("D3 %d %d %d\n", D3.GetDay(), D3.GetMonth(), D3.GetYear());

	++D1;
	printf("\n+1 month to D1:\n\t %d %d %d\n", D1.GetDay(), D1.GetMonth(), D1.GetYear());
	D2++;
	printf("\n+1 day to D2:\n\t %d %d %d\n", D2.GetDay(), D2.GetMonth(), D2.GetYear());
	if (D1 > D2) {
		printf("\n���� D1 �i��� �i���\n");
	}
	else {
		printf("\n���� D2 �i��� �i���\n");
	}
	printf("\n����i�, �� ��������� �� �i��� ���� ��� D3: %d ��i�", D3.DaysBeforeNextYear());
}