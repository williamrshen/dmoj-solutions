#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 5005;
int n, dp[2][MN];
string s;


int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> s;
	int c = 0, p = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				dp[c][j] = dp[p][j - 1];
			}
			else {
				dp[c][j] = min(dp[c][j - 1], dp[p][j]) + 1;
			}
		}
		c = 1 - c;
		p = 1 - p;
	}
	cout << dp[p][n - 1] << ok;
}