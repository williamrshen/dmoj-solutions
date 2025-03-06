#include <iostream>

using namespace std;

#define ok "\n"
#define MN 1005

int d, x, r, dp[MN][MN];
string a, b;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> d >> x >> r >> a >> b;
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			if (i == 0 || j == 0) {
				if (j != 0) dp[i][j] = j * x;
				else if (i != 0) dp[i][j] = i * d;
				else dp[i][j] = 0;
			}
			else {
				if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = min(min(dp[i][j - 1] + x, dp[i - 1][j] + d), dp[i - 1][j - 1] + r);
			}
		}
	}
	cout << dp[a.size()][b.size()] << ok;
}