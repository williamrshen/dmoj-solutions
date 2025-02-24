#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;


#define ok "\n"
#define pb push_back


const int MN = 100;
int x, n, c[MN], dp[10005];


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	fill(dp, dp + 10005, 999999999);
	dp[0] = 0;
	for (int i = 1; i <= x; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - c[j] < 0) continue;
			dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
	cout << dp[x] << ok;
}