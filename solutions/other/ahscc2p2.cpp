// ahscc2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;
int score = 0;


int main()
{
	cin >> n >> k >> s;
	int cur = 0;
	bool per = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') {
			score += 2;
			cur++;
			if (per) {
				cout << "NO" << "\n";
				return 0;
			}
			if (cur > k) {
				cout << "NO\n";
				return 0;
			}
			per = true;
		}
		else {
			per = false;
			if (s[i] == 'S') {
				score++;
				cur++;
				if (cur > k) {
					cout << "NO\n";
					return 0;
				}
			}
			else if (s[i] == 'F') {
				cur = 0;
			}
		}
	}
	cout << "YES\n" << score;
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