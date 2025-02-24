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

const int MN = 1e7 + 5;
int n, s[MN];


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	long long right = 0, left = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		right += s[i];
	}
	int idx = 1;
	while (idx <= n) {
		if (right == left) {
			cout << idx - 1 << ok;
			return 0;
		}
		else {
			left += s[idx];
			right -= s[idx];
			idx++;
		}
	}
	cout << "Andrew is sad." << ok;
}