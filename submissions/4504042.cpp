#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define ok "\n"
#define MN 1505
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, m, g[MN][MN];
bool one = 1;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	scan(n); scan(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scan(g[i][j]);
			if (g[i][j] != 0) {
				one = 0;
			}
		}
	}
	if (n == -1 && one) {
		for (int i = 1; i <= m; i++) {
			cout << i << " ";
		}
		cout << ok;
	}
	else if (n == -1) {
		int c = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << c++ << " "; // haha c++
			}
			cout << ok;
		}
	}
	else if (n == -1) {
		int c = 1;
		for (int i = 1; i <= m; i++) {
			if (g[n][i] == 0) {
				g[n][i] = c++;
			}
			else {
				if (g[n][i] <= g[n][i - 1]) {
					cout << -1 << ok;
					return 0;
				}
				else {
					c = g[n][i] + 1;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << g[n][i] << " ";
		}
		cout << ok;
	}
	else {
		int c = 1;
		for (int i = 1; i <= m; i++) {
			if (g[1][i] == 0) {
				g[1][i] = c++;
			}
			else {
				if (g[1][i] <= g[1][i - 1]) {
					cout << -1 << ok;
					return 0;
				}
				else {
					c = g[1][i] + 1;
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == 0) {
					if (j == 1) {
						g[i][j] = g[i - 1][j] + 1;
					}
					else {
						g[i][j] = max(g[i][j - 1], g[i - 1][j]) + 1;
					}
				}
				else {
					if (g[i][j] <= g[i][j - 1] || g[i][j] <= g[i - 1][j]) {
						cout << -1 << ok;
						return 0;
					}
					else {
						c = g[i][j] + 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << g[i][j] << " ";
			}
			cout << ok;
		}
	}
}