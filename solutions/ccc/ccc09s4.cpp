#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 5005, INF = 0x3f3f3f3f;
int n, t, a, b, c, k, d, vis[MN], dis[MN], out = INF;
vector<pi> city;
vector<pi> adj[MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        city.push_back({ a, b });
    }
    fill(dis, dis + MN, INF);
    cin >> d; dis[d] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({ 0, d });
    while (!q.empty()) {
        int cc = q.top().first;
        int cn = q.top().second;
        q.pop();
        if (vis[cn]) continue;
        vis[cn] = 1;
        for (auto e : adj[cn]) {
            int nc = e.first;
            int nn = e.second;
            if (nc + cc < dis[nn]) {
                dis[nn] = nc + cc;
                q.push({ dis[nn], nn });
            }
        }
    }
    for (auto e : city) {
        dis[e.first] += e.second;
        if (dis[e.first] < out) {
            out = dis[e.first];
        }
    }
    cout << out << ok;
}