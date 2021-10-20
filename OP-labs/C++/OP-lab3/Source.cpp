#include <iostream>
using namespace std;

//double factorial(int n) {
//	double res = 1;
//	for (int i = 1; i <= n; i++) {
//		res = res * i;
//	}
//	return res;
//}

int main() {
	double x; cin >> x;
	int k = 0; double current_x, next_x = 0;
	const double precision = 0.00001;
	double factorial;
	double sum = 0, diff;
	do {
		factorial = 1;
		for (int i = 1; i <= k; i++) {
			factorial = factorial * i;
		}
		current_x = next_x;
		next_x = pow(x, 2 * k) / (pow(2, k) * factorial);
		sum += next_x;
		diff = abs(next_x - current_x);
		k++;
	} while (diff >= precision);
	cout << sum << ' ' << k + 1;
} 