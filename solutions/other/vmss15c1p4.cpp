#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define ok "\n"
#define pi pair<int, int>

const int MN = 2005, INF = 0x3f3f3f3f;
int t, n, m, g, a, b, c, dis[MN], vis[MN], out = 0;
vector<int> fb;
vector<pi> adj[MN];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t >> n >> m >> g;
    for (int i = 0, x; i < g; i++) {
        cin >> x;
        fb.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    fill(dis, dis + MN, INF);
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({ 0, 0 }); dis[0] = 0;
    while (!q.empty()) {
        int cc = q.top().first;
        int cn = q.top().second;
        q.pop();
        if (vis[cn]) continue;
        vis[cn] = 1;
        for (auto x : adj[cn]) {
            int nn = x.first;
            int nc = x.second;
            if (cc + nc < dis[nn]) {
                dis[nn] = cc + nc;
                q.push({ cc + nc, nn });
            }
        }
    }
    for (int x : fb) {
        if (dis[x] < t) out++;
    }
    cout << out << ok;
}