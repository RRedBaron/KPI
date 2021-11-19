#include <iostream>

int factorial(int a);
int AmountOfNumbers(int k, int n);
int Max(int a, int b);

int main() {
	setlocale(LC_ALL, "rus");
	int a = Max(AmountOfNumbers(3, 5), Max(AmountOfNumbers(2, 4), AmountOfNumbers(4, 5)));
	if (a == AmountOfNumbers(3, 5)) std::cout << "трьохзназначних чисел, що записуються цифрами 1, 2, 3, 4, 5";
	else if (a == AmountOfNumbers(2, 4)) std::cout << "двозназначних чисел, що записуються цифрами 2, 4, 6, 8";
	else std::cout << "чотирьохзназначних чисел, що записуються цифрами 1, 3, 7, 8, 9";
}

int factorial(int a) {
	int factorial = 1;
	for (int i = 1; i <= a; i++) {
		factorial *= i;
	}
	return factorial;
}

int AmountOfNumbers(int k, int n) {
	return factorial(n) / factorial(n - k);
}

int Max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
