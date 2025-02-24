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

const int MN = 1005;
int n, m, a, b, c, dis[MN], vis[MN];
vector<pi> adj[MN];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	
	fill(dis, dis + MN, 0x3f3f3f3f);
	fill(vis, vis + MN, 0);
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({ 0, 1 }); dis[1] = 0;
	while (!q.empty()) {
		int cc = q.top().first;
		int cn = q.top().second;
		q.pop();
		if (vis[cn]) continue;
		vis[cn] = 1;
		for (auto x : adj[cn]) {
			int nc = x.first;
			int nn = x.second;
			if (nc + cc < dis[nn]) {
				dis[nn] = nc + cc;
				q.push({ dis[nn], nn });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (vis[i] ? dis[i] : -1) << ok;
	}
}