// yac9p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>


using namespace std;

#define MN 200005
int n, ans = 1;
int s[MN], t[MN];
map<int, int> mp;

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		mp[t[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		if (s[i - 1] != t[mp[s[i]] - 1]) {
			ans++;
		}
	}
	cout << ans << "\n";
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