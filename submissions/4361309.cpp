#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;


#define ok "\n"
#define pb push_back

const int MN = 100005;
int n, a[MN], b[MN], dp[MN]; //0 french, 1 english

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	dp[1] = max(b[1], a[1]); dp[2] = dp[1] + max(b[2], a[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + b[i];
		dp[i] = max(dp[i], max(a[i], b[i]) + b[i - 1] + dp[i - 2]);
		dp[i] = max(dp[i], max(a[i], b[i]) + max(a[i - 1], b[i - 1]) + b[i - 2] + dp[i - 3]);
	}
	cout << dp[n] << ok;
}