#include <iostream>

int main() {
	
	setlocale(LC_ALL, "rus");

	double x1, y1, x2, y2, x3, y3;
	std::cout << "������� ���������� ����� � ������� (� �)\n";
	std::cin >> x1 >> y1;
	std::cout << "������� ���������� ����� � ������� (� �)\n";
	std::cin >> x2 >> y2;
	std::cout << "������� ���������� ����� � ������� (� �)\n";
	std::cin >> x3 >> y3;
	double dist1, dist2, dist3;
	dist1 = hypot(x1, y1);
	dist2 = hypot(x2, y2);
	dist3 = hypot(x3, y3);
	if (dist1 <= dist2) {
		if (dist1 <= dist3) std::cout << "�.1 - ��������� � ������ ���������";
		else std::cout << "�.3 - ��������� � ������ ���������";
	}
	else {
		if (dist2 <= dist3) std::cout << "�.2 - ��������� � ������ ���������";
		else std::cout << "�.3 - ��������� � ������ ���������";
	}
}