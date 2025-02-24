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

const int MN = 10005, INF = 0x3f3f3f3f;
int n, m, k, x, y;
vector<int> adj[MN];
bool vis[MN];

int bfs(int x, int y) {
	queue<int> q; q.push(x);
	int dis[MN]; fill(dis, dis + MN, -1);  dis[x] = 0;
	while (q.size()) {
		int c = q.front(); q.pop();
		for (int e : adj[c]) {
			if (dis[e] == -1) {
				dis[e] = dis[c] + 1;
				q.push(e);
			}
		}
		if (dis[y] != -1) {
			return dis[y];
		}
	}
	return dis[y];
}

void s() {
	queue<int> q; q.push(1);
	fill(vis, vis + MN, 0); vis[1] = true;
	while (q.size()) {
		int c = q.front(); q.pop();
		for (int e : adj[c]) {
			if (!vis[e]) {
				vis[e] = true;
				q.push(e);
			}
		}
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> k;
	while (k--) {
		cin >> x >> y;
		int dis = bfs(x, y);
		if (dis != -1) {
			cout << "Y" << " " << dis << ok;
		}
		else cout << "N" << ok;
	}
	s();
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "N" << ok;
			return 0;
		}
	}
	if (n - 1 == m) {
		cout << "Y" << ok;
	}
	else cout << "N" << ok;
}