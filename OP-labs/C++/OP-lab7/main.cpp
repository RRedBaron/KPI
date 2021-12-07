#include <iostream>

using namespace std;

void FillArray(int M[], int n) {
	cout << "Enter your array: "; 
	for (int i = 0; i < n; i++) {
		cin >> M[i];
	}
}

int SumOfElements(int M[], int n, int k, int t) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += M[i] >= k ? M[i] <= t ? M[i] : 0 : 0;
	}
	return sum;
}

int AmountOfElements(int M[], int n, int k, int t) {
	int amount = 0;
	for (int i = 0; i < n; i++) {
		amount += M[i] >= k ? M[i] <= t ? 1 : 0 : 0;
	}
	return amount;
}

void ChangeElementsOfArray(int M[], int n, int k, int t, int sum) {
	for (int i = 0; i < n; i++) {
		M[i] += M[i] >= k ? M[i] <= t ? sum : 0 : 0;
	}
}

void PrintArray(int M[], int n) {
	cout << "Your array is: ";
	for (int i = 0; i < n; i++) {
		cout << M[i] << ' ';
	}
}

int main() {
	int n; cout << "Enter the size of your array: "; cin >> n;
	int* M = new int[n];
	int k; cout << "Enter the number k: "; cin >> k;
	int t; cout << "Enter the number t: "; cin >> t;
	FillArray(M, n);
	if (AmountOfElements(M, n, k, t)) {
		cout << "Amount of elements [k, t]: " << AmountOfElements(M, n, k, t) << '\n' << "Sum of elements [k, t]: " << SumOfElements(M, n, k, t) << '\n';
	}
	else {
		cout << "There are no such elements" << endl;
		return 0;
	}
	ChangeElementsOfArray(M, n, k, t, SumOfElements(M, n, k, t));
	PrintArray(M, n);
	delete[] M;
	return 0;
}