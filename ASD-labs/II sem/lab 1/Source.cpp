#include <iostream>

using namespace std;

void BubbleSort(int* arr, int size);
void RandomInput(int* arr, int size);
void WorstInput(int* arr, int size);
void PerfectInput(int* arr, int size);
void CombSort(int* arr, int size);
void PrintArray(int* arr, int size);
void CopyArray(int* originalarray, int* copyarray, int size);

int main() {
	cout << "Enter the size of your array: ";
	int size; cin >> size;
	int* unsorted_arr = new int[size];
	int* sorted_arr = new int[size];
	
	cout << "\n\n=====PERFECT ARRAY=====" << endl;
	PerfectInput(unsorted_arr, size);
	PrintArray(unsorted_arr, size);
	CopyArray(unsorted_arr, sorted_arr, size);
	BubbleSort(sorted_arr, size);
	cout << "Sorted array:\t";
	PrintArray(sorted_arr, size);
	CopyArray(unsorted_arr, sorted_arr, size);
	CombSort(sorted_arr, size);
	cout << "Sorted array:\t";
	PrintArray(sorted_arr, size);

	cout << "\n\n=====WORST ARRAY=====" << endl;
	WorstInput(unsorted_arr, size);
	PrintArray(unsorted_arr, size);
	CopyArray(unsorted_arr, sorted_arr, size);
	BubbleSort(sorted_arr, size);
	cout << "Sorted array:\t";
	PrintArray(sorted_arr, size);
	CopyArray(unsorted_arr, sorted_arr, size);
	CombSort(sorted_arr, size);
	cout << "Sorted array:\t";
	PrintArray(sorted_arr, size);

	cout << "\n\n=====RANDOM ARRAY=====" << endl;
	RandomInput(unsorted_arr, size);
	PrintArray(unsorted_arr, size);
	CopyArray(unsorted_arr, sorted_arr, size);
	BubbleSort(sorted_arr, size);
	cout << "Sorted array:\t";
	PrintArray(sorted_arr, size);
	CopyArray(unsorted_arr, sorted_arr, size);
	CombSort(sorted_arr, size);
	cout << "Sorted array:\t";
	PrintArray(sorted_arr, size);

	delete[] unsorted_arr;
	delete[] sorted_arr;
}

void CopyArray(int* originalarray, int* copyarray, int size) {
	for (int i = 0; i < size; i++) {
		copyarray[i] = originalarray[i];
	}
}

void PrintArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void PerfectInput(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

void WorstInput(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = size - i;
	}
}

void RandomInput(int* arr, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % RAND_MAX;
	}
}

void BubbleSort(int* arr, int size) {
	int comparisons = 0, permutations = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			comparisons++;
			if (arr[j] > arr[j + 1]) {
				permutations++;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\tBUBBLE SORT\nAmount of comparisons: %d\nAmount of permutations: %d\n", comparisons, permutations);
}

int GetGap(int gap) {
	gap /= 1.247;
	if (gap < 1) {
		return 1;
	}
	return gap;
}

void CombSort(int* arr, int size) {
	int gap = size, comparisons = 0, permutations = 0;
	bool is_swapped = true;
	while (is_swapped || gap != 1) {
		gap = GetGap(gap);
		is_swapped = false;
		for (int i = 0; i < size - gap; i++) {
			comparisons++;
			if (arr[i] > arr[i + gap]) {
				permutations++;
				int temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				is_swapped = true;
			}
		}
	}
	printf("\tCOMB SORT\nAmount of comparisons: %d\nAmount of permutations: %d\n", comparisons, permutations);
}