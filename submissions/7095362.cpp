#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

#define ok "\n"
#define make(a, b) uniform_int_distribution<int>(a, b)(rr)

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

int main(int argc, char** argv) {
	//int hm = 6;
	string S = "", T = "";
	cin >> S >> T;

	unordered_set<string> out = solve(S, T);
	for (auto x : out) {
		cout << x << ok << flush;
	}
}