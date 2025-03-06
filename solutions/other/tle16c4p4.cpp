// tle16c4p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define ok "\n"
#define int long long

const int MN = 1e5 + 5;
int n, m, q, pre[MN], f;
vector<pair<int, int>> adj[MN];
vector <ll> rs;
ll dis[MN], d, ans;
bool vis[MN];

void dfs(int cur, int par, int dd) {
    dis[cur] = dd;
    pre[cur] = par;
    vis[cur] = 1;
    if (dd > d) {
        d = dd;
        f = cur;
    }
    for (auto x : adj[cur]) {
        if (x.first != par) {
            dfs(x.first, cur, dd + x.second);
        }
    }
}

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        d = -1;
        dfs(i, 0, 0);
        d = -1;
        dfs(f, 0, 0);
        if (q == 1) {
            ans += d + 1;
            continue;
        }
        ll r = 1e18;
        for (int i = f; i; i = pre[i]) {
            r = min(r, max(dis[i], d - dis[i]));
        }
        rs.push_back(r);
    }
    if (q == 1) {
        cout << ans - 1 << ok;
    }
    else {
        sort(rs.rbegin(), rs.rend());
        if (rs.size() > 1 && rs[0] == rs[1]) {
            cout << rs[0] + 1 << ok;
        }
        else {
            cout << rs[0] << ok;
        }
    }
}