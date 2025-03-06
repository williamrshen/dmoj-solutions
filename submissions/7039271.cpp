// ccc08j4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string l;

int main()
{
	while (true) {
		getline(cin, l);
		if (l == "0") {
			break;
		}
		stack<string> s;
		for (int i = l.size() - 1; i >= 0; i--) {
			if (l[i] == ' ') {
				continue;
			}
			if ('1' <= l[i] && l[i] <= '9') {
				s.push({ l[i] });
			}
			else {
				string one = s.top();
				s.pop();
				string two = s.top();
				s.pop();
				string result = one + " " + two + " " + l[i];
				s.push(result);
			}
		}
		cout << s.top() << "\n";
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