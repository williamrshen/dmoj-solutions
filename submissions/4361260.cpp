#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;


#define ok "\n"
#define pb push_back

const int MN = 100005;
int n, dp[MN][3], act[MN][3];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> act[i][0];
		cin >> act[i][1];
		cin >> act[i][2];
	}
	//dp[1][0] = act[1][0];
	//dp[1][1] = act[1][1];
	//dp[1][2] = act[1][2];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = act[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = act[i][1] + max(dp[i - 1][2], dp[i - 1][0]);
		dp[i][2] = act[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
	}
	cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << ok;
}