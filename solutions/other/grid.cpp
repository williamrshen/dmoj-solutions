#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 1005;
int n, q, g[MN][MN], r[MN], c[MN], d = 0;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		r[i] = i;
		c[i] = i;
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int o; cin >> o;
		if (o == 1) {
			int a, b; cin >> a >> b;
			if (d % 2 == 0) {
				swap(r[a], r[b]);
			}
			else {
				swap(c[a], c[b]);
			}
		}
		else if (o == 2) {
			int a, b; cin >> a >> b;
			if (d % 2 == 0) {
				swap(c[a], c[b]);
			}
			else {
				swap(r[a], r[b]);
			}
		}
		else {
			int x; cin >> x;
			d += x;
			d %= 4;
		}
	}
	if (d == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << g[r[i]][c[j]] << (j == n ? ok : " ");
			}
		}
	}
	else if (d == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << g[r[(n + 1) - j]][c[i]] << (j == n ? ok : " ");
			}
		}
	}
	else if (d == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << g[r[(n + 1) - i]][c[(n + 1) - j]] << (j == n ? ok : " ");
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << g[r[j]][c[(n + 1) - i]] << (j == n ? ok : " ");
			}
		}
	}
}