#include <iostream>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 5005;
int N, m, dp[MN], ans = -1 * 0x3f3f3f3f;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N >> m;
	for (int i = 1; i <= N; i++) {
		int n, v, p;
		cin >> n >> v >> p;
		for (int j = 1; j <= n; j *= 2) {
			int V = j * v, P = j * p;
			for (int k = MN - 1; k >= V; k--) dp[k] = max(dp[k], dp[k - V] + P);
			n -= j;
		}
		if (n) {
			int V = n * v, P = n * p;
			for (int j = MN - 1; j >= V; j--) dp[j] = max(dp[j], dp[j - V] + P);
		}
	}
	for (int i = 1; i <= m; i++) {
		int c, f; cin >> c >> f;
		ans = max(ans, dp[c] - f);
	}
	cout << ans << ok;
}