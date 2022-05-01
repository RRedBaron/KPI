//23. Побудувати два бінарних дерева, елементами якого є цілі числа. Oб'єднати
//їх, уникаючи дублювання елементів в сумарному дереві.

#include "tree.h"

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "Введите количество n элементов дерева: ";
	int n; cin >> n;
	Branch* root1 = NULL;
	int m;
	cout << "Введите n элементов дерева: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		AddElement(root1, m);
	}
	print_tree(root1);
	Branch* root2 = NULL;
	cout << "Введите количество n элементов дерева: ";
	cin >> n;
	cout << "Введите n элементов дерева: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		AddElement(root2, m);
	}
	print_tree(root2);
	vector <int> base;
	pr_obh(root1, base);
	pr_obh(root2, base);
	Branch* root3 = NULL;
	for (const auto& i : base) {
		AddElement(root3, i);
	}
	cout << "Объединенное дерево без дублирования элементов: " << endl;
	print_tree(root3);
}
