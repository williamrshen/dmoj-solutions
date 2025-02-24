/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

string s, t;

void find(string res, string s, string t, unordered_set<string> &ret) {
	if (!s.length() && !t.length()) {
		ret.insert(res);
		return;
	}
	if (s.length()) {
		find(res + s[0], s.substr(1), t, ret);
	}
	if (t.length()) {
		find(res + t[0], s, t.substr(1), ret);
	}
}

unordered_set<string> solve(string s, string t) {
	unordered_set<string> ret;
	if (!s.length() && !t.length()) {
		return ret;
	}
	find("", s, t, ret);
	return ret;
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> s >> t;
    unordered_set<string> out = solve(s, t);
    for (auto x : out) {
        cout << x << "\n";
    }
}