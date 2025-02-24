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
	for (int i = 0; i < n; i++) {
		int k = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (k == -1 || d[j] < d[k])) {
				k = j;
			}
		}
		if (k == -1 || d[k] == inf) break;
		vis[k] = true;
		for (auto e : adj[k]) {
			int to = e.first;
			int weight = e.second;
			if (d[k] + weight < d[to]) {
				d[to] = d[k] + weight;
			}
		}
	}
	cout << 0 << ok;
	for (int i = 2; i <= n; i++) {
		if (d[i] == inf) cout << -1 << ok;
		else cout << d[i] << ok;
	}
}