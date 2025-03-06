#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

#define speed cin.sync_with_stdio(0); cin.tie(0);
#define int long long
#define pi pair<int, int>

const int mn = 6005, l = 14;
int n, q, u, v, w, bl[mn][l], dep[mn], dis[mn];
vector<pi> a[mn];

void dfs(int c, int p, int d, int dd) {
    dep[c] = d;
    dis[c] = dd;
    bl[c][0] = p;
    for (int i = 1; i < l; i++) bl[c][i] = bl[bl[c][i - 1]][i - 1];
    for (auto x : a[c]) {
        if (x.first == p) continue;
        dfs(x.first, c, d + 1, dd + x.second);
    }
}

int solve(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = l - 1; i >= 0; i--) if (dep[bl[u][i]] >= dep[v]) u = bl[u][i];
    if (u == v) return u;
    for (int i = l - 1; i >= 0; i--) if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    return bl[u][0];
}


signed main() {
    speed
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        u++; v++;
        a[u].push_back({ v, w });
        a[v].push_back({ u, w });
    }
    dfs(1, 0, 0, 0);
    cin >> q;
    while (q--) {
        cin >> u >> v;
        u++; v++;
        cout << dis[u] + dis[v] - 2 * dis[solve(u, v)] << "\n";
    }
    
    return 0;
}