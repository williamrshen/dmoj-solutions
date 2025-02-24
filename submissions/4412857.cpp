#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ok "\n"
#define int long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define MN 1005

char _;
int n, a[MN], b[MN], dp[MN][MN];
string s, t;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> t;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				if (s[i - 1] == 'W' && t[j - 1] == 'L' && a[i - 1] > b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + a[i - 1] + b[j - 1];
				}
				if (s[i - 1] == 'L' && t[j - 1] == 'W' && a[i - 1] < b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + a[i - 1] + b[j - 1];
				}
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}
	cout << dp[n][n] << ok;
}