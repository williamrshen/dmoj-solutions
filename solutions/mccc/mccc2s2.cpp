#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

int n;
string s;

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> s;
	deque<char> dq;
	dq.push_front(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] <= dq.front()) {
			dq.push_front(s[i]);
		}
		else {
			dq.push_back(s[i]);
		}
	}
	while (dq.size()) {
		cout << dq.front();
		dq.pop_front();
	}
}