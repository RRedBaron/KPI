#include "Header.h"

int main() {
	int rows1 = 0, rows2 = 0, count = 0;
	cout << "To stop entering the text press ENTER\n";
	CreateTextFile("mytext.txt", rows1);
	cout << "To stop entering the text press ENTER\n";
	CreateTextFile("mytext2.txt", rows2);
	CreateFileWithSimilarRows("mytext3.txt", rows1, rows2, count);
	cout << "Amount of similar rows:" << count << "\n\n";
	PrintFile("mytext.txt");
	PrintFile("mytext2.txt");
	PrintFile("mytext3.txt");
}