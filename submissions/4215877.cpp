#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 2005, INF = 0x3f3f3f3f;
int t, n, m, g, vis[MN], dis[MN];
vector<int> fb;
vector<pi> adj[MN];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> t >> n >> m >> g;
	while (g--) {
		int x;
		cin >> x;
		fb.push_back(x);
	}
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({ z, y });
	}

	fill(dis, dis + MN, INF);
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({ 0, 0 }); dis[0] = 0;
	while (q.size()) {
		int cc = q.top().first, cn = q.top().second; q.pop();
		if (!vis[cn]) {
			vis[cn] = 1;
			for (auto x : adj[cn]) {
				int nc = x.first, nn = x.second;
				if (nc + cc < dis[nn]) {
					dis[nn] = nc + cc;
					q.push({ nc + cc, nn });
				}
			}
		}
	}
	int ans = 0;
	for (int x : fb) {
		if (dis[x] <= t) {
			ans++;
		}
	}
	cout << ans << ok;
}