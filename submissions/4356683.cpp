#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int N = 1e5 + 10;
vector<int> g[N];
int t[N], colour[N], best[N];  // 0: not vis, 1: parent, 2: not parent

bool dfs(int u) {
    colour[u] = 1;
    for (int v : g[u]) {
        if (colour[v] == 1) return false;
        if (colour[v] == 0) {
            if (!dfs(v)) return false;
        }
        best[u] = max(best[u], best[v] + t[v]);
    }
    colour[u] = 2;
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        int sz;
        cin >> sz;
        g[i].resize(sz);
        for (int &j : g[i]) cin >> j, --j;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (colour[i] == 0 && dfs(i)) {
            ans = max(ans, best[i] + t[i]);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        solve();
    }
}