#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MN = 100005;
int n, m, x, dis[MN], vis[MN], dis2[MN], vis2[MN];
vector<pi> fadj[MN];
vector<pi> radj[MN];

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    scan(n); scan(m); scan(x);
    for (int i = 0; i < m; i++) {
        int a, b, c; scan(a); scan(b); scan(c);
        fadj[a].push_back({ c, b });
        radj[b].push_back({ c, a });
    }

    priority_queue<pi, vector<pi>, greater<pi>> q; 
    
    fill(dis, dis + MN, 99999999);
    fill(vis, vis + MN, 0);
    dis[x] = 0;
    q.push({ 0, x });
    while (q.size()) {
        int cn = q.top().second;
        int cc = q.top().first;
        q.pop();
        if (vis[cn]) {
            continue;
        }
        vis[cn] = 1;
        for (auto x : fadj[cn]) {
            int nn = x.second;
            int nc = x.first;
            if (nc + cc < dis[nn]) {
                dis[nn] = nc + cc;
                q.push({ dis[nn], nn });
            }
        }
    }

    fill(dis2, dis2 + MN, 99999999);
    fill(vis2, vis2 + MN, 0);
    dis2[x] = 0;
    q.push({ 0, x });
    while (q.size()) {
        int cn = q.top().second;
        int cc = q.top().first;
        q.pop();
        if (vis2[cn]) {
            continue;
        }
        vis2[cn] = 1;
        for (auto x : radj[cn]) {
            int nn = x.second;
            int nc = x.first;
            if (nc + cc < dis2[nn]) {
                dis2[nn] = nc + cc;
                q.push({ dis2[nn], nn });
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dis2[i] + dis[i]);
    }
    cout << ans << ok;
}