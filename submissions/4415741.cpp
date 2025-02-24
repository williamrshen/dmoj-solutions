#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define mpr make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) (int)(x.size())

typedef long long ll;	typedef long double ld;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
	int n; cin >> n;
	string s, t; cin >> s;
	int a[n+1], b[n+1], dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> t;
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (((s[i-1] == 'W' && t[j-1] == 'L') && (a[i] > b[j])) || ((s[i-1] == 'L' && t[j-1] == 'W') && (a[i] < b[j]))) dp[i][j] = a[i] + b[j] + dp[i-1][j-1];
			dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
		}
	}
	cout << dp[n][n] << endl;
}