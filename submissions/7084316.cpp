// ccc22s2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int x, y, g, violations;
vector<pair<string, string>> same;
vector<pair<string, string>> diff;
map<string, int> group;


int main()
{
	cin >> x;
	for (int i = 0; i < x; i++) {
		string p1, p2;
		cin >> p1 >> p2;
		same.push_back({ p1, p2 });
	}

	cin >> y;
	for (int i = 0; i < y; i++) {
		string p1, p2;
		cin >> p1 >> p2;
		diff.push_back({ p1, p2 });
	}

	cin >> g;
	for (int i = 1; i <= g; i++) {
		string p1, p2, p3;
		cin >> p1 >> p2 >> p3;
		group[p1] = i;
		group[p2] = i;
		group[p3] = i;
	}

	for (auto x : same) {
		string p1 = x.first;
		string p2 = x.second;
		if (group[p1] != group[p2]) {
			violations++;
		}
	}

	for (auto x : diff) {
		string p1 = x.first;
		string p2 = x.second;
		if (group[p1] == group[p2]) {
			violations++;
		}
	}
	cout << violations << "\n";
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