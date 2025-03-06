#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 100005, INF = 0x3f3f3f3f;
int n, m;
pi dis[MN];
vector<pi> adj[MN];
bool vis[MN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }
    for (int i = 1; i < MN; i++) {
        dis[i] = { INF, INF };
    }
    priority_queue<pair<pi, int>, vector<pair<pi, int>>, greater<pair<pi, int>>>q;
    memset(dis, INF, sizeof(dis));
    dis[1] = { 0, 0 };
    q.push({ dis[1], 1 });
    
    while (q.size()) {
        auto cur = q.top(); q.pop();
        pi d = cur.first;
        int u = cur.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : adj[u]) {
            int a = x.second, b = x.first;
            pi hm = { dis[u].first + b, dis[u].second + 1 };
            if (dis[a] > hm) {
                dis[a] = hm;
                q.push({ dis[a], a });
            }
        }
    }
    if (!vis[n]) cout << -1 << ok;
    else cout << dis[n].first << " " << dis[n].second << ok;
}