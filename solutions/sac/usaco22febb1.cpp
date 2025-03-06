#include <iostream>

using namespace std;

#define ok "\n"
#define MN 100005

int t, n, arr[MN];

void solve(int s) {
	for (int i = n; i > 0; i--) {
		if (s % i == 0) {
			int c = 0, a = 1;
			for (int j = 1; j <= n; j++) {
				c += arr[j];
				if (c > s / i) {
					a = 0;
					break;
				}
				else if (c == s / i) {
					c = 0;
				}
			}
			if (a) {
				cout << n - i << ok;
				return;
			}
		}
	}
}

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int s = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			s += arr[i];
		}
		solve(s);
	}
}