#include "Worker.h"

int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ������ ������ �������: ";
	size_t size; cin >> size;
	cin.ignore();
	Worker* arr = new Worker[size];
	cout << "������� ���������� � ������� [������� ��� �������� ��-��-����]\n";
	for (int i = 0; i < size; i++) {
		string str; getline(cin, str);
		arr[i] = str;
	}
	Worker a = arr[0];
	cout << "������� ���� � ������� ��-��-����: ";
	string date; getline(cin, date);
	cout << "������� ����������� �� ��������� �� ��������� ����:\n";
	Worker oldest = arr[0];
	for (int i = 0; i < size; i++) {
		arr[i].ShowAgeOnGivenDate(date);
		if (arr[i] > oldest) oldest = arr[i];
	}
	cout << "C������ ����� �����������: " << oldest.GetName() << endl;
	delete[] arr;
}