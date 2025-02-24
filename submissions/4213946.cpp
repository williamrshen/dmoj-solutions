#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define ok "\n"
#define pi pair<int, int>

const int MN = 1005;
int n, m, a, b, c, vis[MN], ans[MN];
vector<pi> adj[MN];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    fill(ans, ans + MN, 1e9);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    priority_queue < pi, vector<pi>, greater<pi> > q;
    ans[1] = 0;
    q.push({ ans[1], 1 });
    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (d + w < ans[v]) {
                ans[v] = d + w;
                q.push({ ans[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (vis[i] ? ans[i] : -1) << ok;
    }
}