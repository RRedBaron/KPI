#include "header.h"

/*�������� ���� �� ������� �볺���, ���������� ���������� �������� ��� :
  �������, ��� ������� �� ��� ��������� ��������������. ��� �������
  ����� ��������� ���� ����������� (�� �� ������������� �볺��� � ��������). 
  �������� ����� ����, ���� ������ ���������� ��� �볺���,
  � ����� �������� ���������� ����� 30 ��.*/

int main() {
	const char* FName1 = "abc.dat";
	const char* FName2 = "dce.dat";
	CreateFile(FName1);
	cout << FName1 << ":\n";
	PrintFile(FName1);
	CreateNewFile(FName1, FName2);
	cout << FName2 << ":\n";
	PrintFile(FName2);
}