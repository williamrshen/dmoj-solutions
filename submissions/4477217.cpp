#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ok "\n"
#define pi pair<int, int>


const int MN = 100005;
int n, m, x, dis1[MN], dis2[MN], vis1[MN], vis2[MN];
vector<pi> adj1[MN], adj2[MN];

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj1[a].push_back({ c, b });
        adj2[b].push_back({ c, a });
    }
    priority_queue<pi, vector<pi>, greater<pi>> q;

    q.push({ 0, x });
    fill(dis1, dis1 + MN, 99999999);
    fill(vis1, vis1 + MN, 0);
    dis1[x] = 0;
    while (q.size()) {
        int cn = q.top().second;
        int cc = q.top().first;
        q.pop();
        if (vis1[cn]) continue;
        vis1[cn] = 1;
        for (auto x : adj1[cn]) {
            int nn = x.second;
            int nc = x.first;
            if (dis1[nn] > nc + cc) {
                dis1[nn] = nc + cc;
                q.push({ nc + cc, nn });
            }
        }
    }

    q.push({ 0, x });
    fill(dis2, dis2 + MN, 99999999);
    fill(vis2, vis2 + MN, 0);
    dis2[x] = 0;
    while (q.size()) {
        int cn = q.top().second;
        int cc = q.top().first;
        q.pop();
        if (vis2[cn]) continue;
        vis2[cn] = 1;
        for (auto x : adj2[cn]) {
            int nn = x.second;
            int nc = x.first;
            if (dis2[nn] > nc + cc) {
                dis2[nn] = nc + cc;
                q.push({ nc + cc, nn });
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dis1[i] + dis2[i]);
    }
    cout << ans << ok;
}