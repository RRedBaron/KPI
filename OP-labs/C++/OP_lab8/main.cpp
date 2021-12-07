#include <iostream>

using namespace std;

int** FillArray(int n, int upper, int lower) {
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	return arr;
}

int FindMaxSumOfRows(int** arr, int n) {
	int sum = 0, maxsum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[i][j];
		}
		if (sum > maxsum) maxsum = sum;
		sum = 0;
	}
	return maxsum;
}

int FindMinSumOfRows(int** arr, int n) {
	int sum = 0, minsum;
	for (int j = 0; j < n; j++) {
		sum += arr[0][j];
	}
	minsum = sum;
	sum = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[i][j];
		}
		if (sum < minsum) minsum = sum;
		sum = 0;
	}
	return minsum;
}

double CalculateT(double max1, double min1, double max2, double min2) {
	double T = (max1 + max2) / (1 + min1 * min2);
	return T;
}

void PrintArray(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void DeleteArray(int** arr, int n) {
	for (int i = 0; i < n; i++) delete arr[i];
	delete[] arr;
}

int main() {
	srand(time(NULL));
	int n; cout << "Enter order of your arrays: "; cin >> n;
	int upper, lower;
	cout << "Enter lower bound of elements in your arrays: "; cin >> lower;
	cout << "Enter upper bound of elements in your arrays: "; cin >> upper;
	int** arr1 = FillArray(n, upper, lower);
	int** arr2 = FillArray(n, upper, lower);
	PrintArray(arr1, n);
	cout << "====================" << endl;
	PrintArray(arr2, n);
	cout << "T = " << CalculateT(FindMaxSumOfRows(arr1, n), FindMinSumOfRows(arr1, n), FindMaxSumOfRows(arr2, n), FindMinSumOfRows(arr2, n));
	DeleteArray(arr1, n);
	DeleteArray(arr2, n);
}