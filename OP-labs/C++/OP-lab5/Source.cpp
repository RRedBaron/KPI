#include <iostream>
int main() {
	int a, b; std::cin >> a >> b;
	int fib1 = 1, fib2 = 1;
	int last = 0, temp;
	std::cout << 1 << std::endl; //1 - делитель любого числа и принадлежит ряду Фибоначчи
	while (fib2 < b) {
		temp = fib1;
		fib1 = fib2;
		fib2 += temp;
		for (int i = a; i < b + 1; i++) {
			if (i % fib2 == 0) {
				if (last != fib2) {
					std::cout << fib2 << std::endl;
					last = fib2;
				}
			}
		}
	}
}