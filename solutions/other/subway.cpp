#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"
#define MN 50005

int n, d, ans, dis[MN], cnt[MN];
vector<int> adj[MN];

void dfs(int cur, int par) {
	dis[cur] = 0;
	cnt[cur] = 1;
	for (int x : adj[cur]) {
		if (x != par) {
			dfs(x, cur);
			if (dis[cur] + dis[x] + 1 > d) {
				d = dis[x] + dis[cur] + 1;
				ans = cnt[cur] * cnt[x];
			}
			else if (dis[cur] + dis[x] + 1 == d) {
				ans += cnt[cur] * cnt[x];
			}
			if (dis[x] + 1 > dis[cur]) {
				dis[cur] = dis[x] + 1;
				cnt[cur] = cnt[x];
			}
			else if (dis[x] + 1 == dis[cur]) {
				cnt[cur] += cnt[x];
			}
		}
	}
}

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	cout << ans << ok;
}