#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 1005
#define pi pair<int, int>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, m, dp[MN][MN];
string a, b;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	cin >> a >> b;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (i == 0 && j == 0) dp[i][j] = 0;
			else if (i == 0) dp[i][j] = (j + 2) / 3;
			else if (j == 0) dp[i][j] = (i + 2) / 3;
			else {
				if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = dp[i - 1][j - 1] + 1;
				for (int k = 1; k <= 3; k++) {
					if (j >= k) dp[i][j] = min(dp[i][j], dp[i][j - k] + 1);
					if (i >= k) dp[i][j] = min(dp[i][j], dp[i - k][j] + 1);
				}
			}
		}
	}
	cout << dp[n][m] << ok;
}