// xorupdate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"

const int MN = 2e5 + 5, LOG = 18;
int n, q, val[MN], dep[MN], bl[LOG][MN], dif[MN];
vector<int> adj[MN];

void dfs(int cur, int par) {
	dep[cur] = dep[par] + 1;
	bl[0][cur] = par;
	for (int i = 1; i < LOG; i++) {
		bl[i][cur] = bl[i - 1][bl[i - 1][cur]];
	}
	for (int x : adj[cur]) {
		if (x != par) {
			dfs(x, cur);
		}
	}
}

int LCA(int u, int v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (dep[bl[i][u]] >= dep[v]) {
			u = bl[i][u];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (bl[i][u] != bl[i][v]) {
			u = bl[i][u];
			v = bl[i][v];
		}
	}
	return bl[0][u];
}

void getpsa(int cur, int par) {
	for (int x : adj[cur]) {
		if (x != par) {
			getpsa(x, cur);
			dif[cur] ^= dif[x];
		}
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= q; i++) {
		int a, b, x; cin >> a >> b >> x;
		int lca = LCA(a, b);
		int dis = dep[a] + dep[b] - 2 * dep[lca];
		dif[a] ^= x;
		if ((dep[a] - dep[lca]) % 2 == 0) {
			val[lca] ^= x;
		}
		if (dis % 2 == 0) {
			dif[b] ^= x;
		}
		else {
			dif[bl[0][b]] ^= x;
		}
	}
	getpsa(1, 0); getpsa(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << (dif[i] ^ val[i]) << " ";
	}
}