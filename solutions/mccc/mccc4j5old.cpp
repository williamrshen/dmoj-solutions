#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 10005, INF = 0x3f3f3f3f;
int n, m, k, x, y, par[MN], ra[MN];
vector<int> adj[MN];
bool viss[MN];

int find(int x) {
    if (x == par[x]) return x;
    else return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (ra[x] < ra[y]) {
            par[y] = x;
        }
        else if (ra[y] < ra[x]) {
            par[y] = x;
        }
        else {
            par[y] = x;
            ra[x]++;
        }
    }
}

int bfs(int x, int y) {
    queue<int> q;
    q.push(x);
    int dis[MN]; fill(dis, dis + MN, INF);
    dis[x] = 0;
    int vis[MN]; fill(vis, vis + MN, 0);
    vis[x] = 1;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int e : adj[c]) {
            if (!vis[e]) {
                vis[e] = 1;
                dis[e] = dis[c] + 1;
                q.push(e);
            }
        }
    }
    if (dis[y] == INF) {
        return -1;
    }
    else return dis[y];
}

bool dfs(int cur, int par) {
    if (viss[cur]) return false;
    viss[cur] = true;
    for (int e : adj[cur]) {
        if (e != par) {
            if (!dfs(e, cur)) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    for (int i = 0; i < MN; i++) {
        par[i] = i; ra[i] = 0;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        merge(x, y);
    }
    cin >> k;
    while (k--) {
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Y " << bfs(x, y) << ok;
        }
        else cout << "N" << ok;
    }
    if (dfs(1, 1)) {
        for (int i = 1; i <= n; i++) {
            if (!viss[i]) {
                cout << "N" << ok;
                return 0;
            }
        }
        cout << "Y" << ok;
    }
    else cout << "N" << ok;
}