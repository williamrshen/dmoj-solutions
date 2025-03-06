#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"

const int MN = 3005;
int n, t[MN];
long long dp[MN][MN];


int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		dp[i][i] = t[i];
	}
	for (int i = n; i > 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = max(t[i] - dp[i + 1][j], t[j] - dp[i][j - 1]);
		}
	}
	cout << dp[1][n] << ok;
}