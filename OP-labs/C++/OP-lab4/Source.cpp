#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	cout << "¬ведите количество n членов р€да: ";
	int n; cin >> n;
	cout << "¬ведите х: ";
	double x; cin >> x;
	double S = 0;
	double factorial = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= i * 2; j++) {
			factorial = factorial * j;
		}
		S += pow(-1, i) * pow(x, 2 * i) / factorial;
		factorial = 1;	
	}
	cout << S;
}	