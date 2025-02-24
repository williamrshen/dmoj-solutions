#include <iostream>
#include <random>
#include <vector>

using namespace std;

#define ok "\n"
#define make(a, b) uniform_int_distribution<int>(a, b)(rr)

const int MN = 1005;
int d, m, n, dp[MN][MN], s[MN][MN]; //dp[i][j] = end at city i after j days
vector<int> adj[MN];

// time complexity is O(DM)

int main(int argc, char** argv) {
	//int hm = atoi(argv[1]);
	int hm = 1;
	mt19937 rr(hm);
	cin >> d >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = s[1][i];
	}
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= n; j++) {
			for (int x : adj[j]) {
				dp[j][i] = max(dp[j][i], dp[x][i - 1] + s[i][j]);
			}
			dp[j][i] = max(dp[j][i], dp[j][i - 1] + s[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][d]);
	}
	cout << ans << ok;
}