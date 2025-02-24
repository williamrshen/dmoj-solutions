#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 405;
int n, arr[MN]; 
long long dp[MN][MN], psa[MN];

int f(int l, int r) {
	if (l == 0) {
		return psa[r];
	}
	else {
		return psa[r] - psa[l - 1];
	}
}


int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	psa[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		psa[i] = psa[i - 1] + arr[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i < n; i++) {
		dp[i][i + 1] = arr[i] + arr[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}
	for (int i = n; i > 0; i--) {
		for (int j = i + 2; j <= n; j++) {
			long long a = 0x3f3f3f3f3f3f3f3f;
			for (int k = i; k < j; k++) {
				a = min(a, dp[i][k] + dp[k + 1][j]);
			}
			dp[i][j] = f(i, j) + a;
		}
	}
	cout << dp[1][n] << ok;
}