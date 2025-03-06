#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;


#define ok "\n"
#define pb push_back

const int MN = 100005;
int n, a[MN], b[MN], dp[MN][2]; //0 french, 1 english

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	dp[1][1] = b[1]; dp[1][0] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][0] = max(a[i] + dp[i - 1][1], a[i] + a[i - 1] + dp[i - 2][1]);
	}
	cout << max(dp[n][0], dp[n][1]) << ok;
}