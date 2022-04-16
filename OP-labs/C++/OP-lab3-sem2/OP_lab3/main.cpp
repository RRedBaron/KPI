#include "Worker.h"

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер вашего массива: ";
	size_t size; cin >> size;
	cin.ignore();
	Worker* arr = new Worker[size];
	cout << "Введите информацию в формате [Фамилия Имя Отчество ММ-ДД-ГГГГ]\n";
	for (int i = 0; i < size; i++) {
		string str; getline(cin, str);
		arr[i] = str;
	}
	Worker a = arr[0];
	cout << "Введите дату в формате ММ-ДД-ГГГГ: ";
	string date; getline(cin, date);
	cout << "Возраст сотрудников по состоянию на введенную дату:\n";
	Worker oldest = arr[0];
	for (int i = 0; i < size; i++) {
		arr[i].ShowAgeOnGivenDate(date);
		if (arr[i] > oldest) oldest = arr[i];
	}
	cout << "Cтарший среди сотрудников: " << oldest.GetName() << endl;
	delete[] arr;
}