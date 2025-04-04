// ccc25j3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> s;
		int len = s.size();
		string code = "";
		int tot = 0;
		for (int i = 0; i < len;) {
			if ('A' <= s[i] && s[i] <= 'Z') {
				code += s[i];
				i++;
			}
			else if (s[i] == '-') {
				i++;
				string num = "";
				for ( ; i < len; i++) {
					if ('0' <= s[i] && s[i] <= '9') {
						num += s[i];
					}
					else {
						break;
					}
				}
				tot -= stoi(num);
			}
			else if ('0' <= s[i] && s[i] <= '9') {
				string num = "";
				for (; i < len; i++) {
					if ('0' <= s[i] && s[i] <= '9') {
						num += s[i];
					}
					else {
						break;
					}
				}
				tot += stoi(num);
			}
			else {
				i++;
			}
		}
		cout << code << tot << "\n";
	}
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