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

const int MN = 5000, INF = 0x3f3f3f3f;
int n, t, k, d, dis[MN], vis[MN];
vector<pi> pp;
vector<pi> adj[MN];


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		pp.push_back({ b, a });
	}
	cin >> d;
	fill(dis, dis + MN, INF);
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({ 0, d }); dis[d] = 0;
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
	int out = INF;
	for (auto x : pp) {
		out = min(out, dis[x.second] + x.first);
	}
	cout << out << ok;
}