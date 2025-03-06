// btoi17p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"

const int MN = 2e5 + 5, LOG = 18;
int n, m, k, cnt, val[MN], dep[MN], bl[LOG][MN], dif[MN], dfn[MN];
vector<pair<int, int>> adj[MN];
vector<int> ans;

void dfs(int cur, int par, int id) {
	val[cur] = id;
	dfn[cur] = ++cnt;
	dep[cur] = dep[par] + 1;
	bl[0][cur] = par;
	for (int i = 1; i < LOG; i++) {
		bl[i][cur] = bl[i - 1][bl[i - 1][cur]];
	}
	for (auto x : adj[cur]) {
		if (x.first != par) {
			dfs(x.first, cur, x.second);
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
	for (auto x : adj[cur]) {
		if (x.first != par) {
			getpsa(x.first, cur);
			dif[cur] += dif[x.first];
		}
	}
	if (dif[cur] >= 2 * k) {
		ans.push_back(val[cur]);
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back({ b, i });
		adj[b].push_back({ a, i });
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= m; i++) {
		int f; cin >> f;
		vector<int> lst;
		for (int j = 1; j <= f; j++) {
			int x; cin >> x;
			lst.push_back(x);
		}
		sort(lst.begin(), lst.end(), [&](int a, int b) {
			return dfn[a] < dfn[b];
			});
		lst.push_back(lst[0]);
		for (int j = 1; j < lst.size(); j++) {
			int u = lst[j - 1], v = lst[j];
			dif[u] ++;
			dif[v] ++;
			dif[LCA(u, v)] -= 2;
		}
	}
	getpsa(1, 0); cout << ans.size() << ok;
	sort(ans.begin(), ans.end());
	for (auto x : ans) {
		cout << x << " ";
	}
}