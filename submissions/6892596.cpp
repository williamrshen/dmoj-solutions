// class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int c, numBlack;
int row1[200005];
int row2[200005];

int main()
{
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> row1[i];
	}
	for (int i = 0; i < c; i++) {
		cin >> row2[i];
	}

	for (int i = 0; i < c; i++) {
		if (row1[i] == 1) {
			numBlack++;
		}
		if (row2[i] == 1) {
			numBlack++;
		}
	}
	numBlack *= 3;
	for (int i = 0; i < c-1; i++) {
		if (row1[i] == 1 && row1[i + 1] == 1) {
			numBlack -= 2;
		}
		if (row2[i] == 1 && row2[i + 1] == 1) {
			numBlack -= 2;
		}
	}

	for (int i = 0; i < c; i++) {
		if (row1[i] == 1 && row2[i] == 1 && i % 2 == 0) {
			numBlack -= 2;
		}
	}
	cout << numBlack << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file