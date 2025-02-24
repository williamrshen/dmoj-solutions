#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

#define ok "\n"


const int mn = 1005, inf = 999999999;
int n, m, u, v, w, d[mn];
vector<pair<int, int>> adj[mn];
bool vis[mn];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	fill(d, d + mn, inf);
	fill(vis, vis + mn, false);
	d[1] = 0;
	queue<int> q; q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto k : adj[x]) {
			if (d[x] + k.second < d[k.first]) {
				q.push(k.first);
				d[k.first] = d[x] + k.second;
			}
		}
	}
	cout << 0 << ok;
	for (int i = 2; i <= n; i++) {
		if (d[i] == inf) cout << -1 << ok;
		else cout << d[i] << ok;
	}
}