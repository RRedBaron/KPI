#include <iostream>;

using namespace std;

int main() {
	double side; cin >> side;
	double Square;
	if (side > 0) {
		Square = sqrt(3) * pow(side, 2) / 4;
		cout << Square;
	}
	else {
		cout << "Triangle does not exist";
	}
}