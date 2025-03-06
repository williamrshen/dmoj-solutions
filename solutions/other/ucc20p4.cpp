#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 1000005;
int n;
long long dp[MN], s[MN];

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + s[i];
		if (i > 1) dp[i] = min(dp[i], dp[i - 2] + max(s[i - 1], s[i]) + min(s[i - 1], s[i]) * 3 / 4);
		if (i > 2) dp[i] = min(dp[i], dp[i - 3] + s[i - 2] + s[i - 1] + s[i] - min(min(s[i - 2], s[i - 1]), s[i]) / 2);
	}

	for (int i = 1; i <= n; i++) {
		//cout << dp[i] << " ";
	}
	cout << dp[n] << ok;
}