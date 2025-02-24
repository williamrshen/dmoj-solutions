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
int n, m, b, Q, vis[MN];
long long dis[MN];
vector<pi> adj[MN];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m >> b >> Q;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({ z, y });
		adj[y].push_back({ z, x });
	}

	fill(dis, dis + MN, INF);
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({ 0, b }); dis[b] = 0;
	while (q.size()) {
		int cc = q.top().first, cn = q.top().second; q.pop();
		if (!vis[cn]) {
			vis[cn] = 1;
			for (auto x : adj[cn]) {
				int nc = x.first;
				int nn = x.second;
				if (nc + cc < dis[nn]) {
					dis[nn] = nc + cc;
					q.push({ nc + cc, nn });
				}
			}
		}
	}
	while (Q--) {
		int x;
		cin >> x;
		cout << (vis[x] ? dis[x] : -1) << ok;
	}
}