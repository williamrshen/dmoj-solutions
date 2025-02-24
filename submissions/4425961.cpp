#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 1005
#define pi pair<int, int>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int INF = 0x3f3f3f3f;
int n, m, a, b, c, dis[MN];
bool vis[MN];
vector<pi> adj[MN]; // weight in first, destination in second

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	memset(dis, INF, sizeof(dis));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	priority_queue<pi, vector<pi>, greater<pi>> q;
	q.push({ 0, 1 }); dis[1] = 0;
	while (q.size()) {
		int cn = q.top().second;
		int cd = q.top().first;
		q.pop();
		if (vis[cn]) continue;
		vis[cn] = 1;
		for (auto x : adj[cn]) {
			int dn = x.second;
			int dd = x.first;
			if (dis[dn] > cd + dd) {
				q.push({ cd + dd, dn });
				dis[dn] = cd + dd;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] == INF) cout << -1 << ok;
		else cout << dis[i] << ok;
	}
}