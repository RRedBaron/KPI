//23. ���������� ��� ������� ������, ���������� ����� � ��� �����. O�'������
//��, �������� ���������� �������� � ��������� �����.

#include "tree.h"

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "������� ���������� n ��������� ������: ";
	int n; cin >> n;
	Branch* root1 = NULL;
	int m;
	cout << "������� n ��������� ������: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		AddElement(root1, m);
	}
	print_tree(root1);
	Branch* root2 = NULL;
	cout << "������� ���������� n ��������� ������: ";
	cin >> n;
	cout << "������� n ��������� ������: ";
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
	cout << "������������ ������ ��� ������������ ���������: " << endl;
	print_tree(root3);
}
