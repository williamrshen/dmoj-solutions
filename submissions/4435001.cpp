#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 150005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int x, n, c[MN], dp[MN];

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> x >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	memset(dp, 999999, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - c[j] >= 0) {
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
			}
		}
	}
	cout << dp[x] << ok;
}