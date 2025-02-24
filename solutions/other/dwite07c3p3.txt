#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 105;
int n, l;
int w[MN], s[MN];
int dp[3000005];

int main() {

	for (int k = 0; k < 5; k++) {
		fill(dp, dp + 30005, 0);
		cin >> l >> n;
		for (int i = 1; i <= n; i++) {
			string m; int a, b; cin >> m >> a >> b;
			w[i] = a; s[i] = b;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 3000005; j >= 0; j--) {
				if (j == 0) {
					dp[j] = 0; continue;
				}
				if (j - s[i] < 0) continue;
				dp[j] = max(dp[j], dp[j - s[i]] + w[i]);
			}
			if (i == n) cout << dp[l] << ok;
		}
	}
}