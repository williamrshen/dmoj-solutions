#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

#define ok "\n"
#define pb push_back


const int MN = 200005;
int n, r, a, b, rab[MN], par[MN];
bool vis[MN];
vector<int> adj[MN];


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> r;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	queue<int> q;

	for (int i = 0; i < r; i++) {
		cin >> a;
		q.push(a);
		vis[a] = 1;
	}

	cin >> a >> b;

	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int x : adj[cur]) {
			if (vis[x]) continue;
			rab[x] = rab[cur] + 1;
			vis[x] = 1;
			q.push(x);
		}
	}

	fill(vis, vis + MN, 0);
	q.push(a); par[a] = -1; vis[a] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int x : adj[cur]) {
			if (vis[x]) continue;
			par[x] = cur;
			vis[x] = 1;
			q.push(x);
		}
	}

	int pre = par[b];
	int ans = rab[b];
	while (pre != -1) {
		ans = min(ans, rab[pre]);
		pre = par[pre];
	}
	cout << ans << ok;
}