/*23. �������� ���� �Date, ���� ������ ����� ����� �����, �� ������������� ��� -
��, ����� �� ��, � ������ ��� ��������� ���, ������� ������ ���������, �� �� -
������� / ��������� �� ������� ��������.�� ����� ����� ����� �������� ����� -
������� TDate1 �� TDate2, �� ������������� ���� � ������ "��.��.����" ��
"��-��-����" ��������.�������� n ��'���� TDate1 �� m ��'���� TDate2.
��������� ���� ���� ����, � ����� ����, �� �������� �������� ������ ���. */

#include "TDate.h"

int main() {
	setlocale(LC_ALL, "rus");
	vector <TDate*> base;
	int n, m;
	string str;
	cout << "������� n >> "; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		base.push_back(new TDate1(str));
	}
	cout << "������� m >> "; cin >> m;
	cin.ignore();
	for (int i = 0; i < m; i++) {
		getline(cin, str);
		base.push_back(new TDate2(str));
	}
	cout << "������ ��������� ��� � ��������������� �������:\n";
	TDate* latest = base[0];
	for (int i = 0; i < m + n; i++) {
		base[i]->ShowDate();
		if (base[i]->CompareDates(*latest)) {
			latest = base[i];
		}
	}
	cout << "����� ������� ���� ����� ���������: ";
	latest->ShowDate();
	string date1, date2;
	cout << "������� ������ ������ ��������� ���: ";
	getline(cin, date1);
	cout << "������� ������� ������ ��������� ���: ";
	getline(cin, date2);
	cout << "����, ������� ������ � �������� ��������:\n";
	for (int i = 0; i < m + n; i++) {
		if (base[i]->IsInTimeInterval(date1, date2)) {
			base[i]->ShowDate();
		}
	}
}