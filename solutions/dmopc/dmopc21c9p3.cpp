// dmopc21c9p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 3005;
int n, m, q, dis[MN][MN];
vector<int> adj[MN];
bool vis[MN];

void bfs(int s, int dis[]) {
    queue<int> q;
    q.push(s);
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (!vis[x]) {
                q.push(x);
                vis[x] = 1;
                dis[x] = dis[cur] + 1;
            }
        }
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, dis[i]);
    }
    cin >> q;
    while (q--) {
        int a, b, c, x, y, z; cin >> a >> b >> c >> x >> y >> z;
        if (dis[a][b] <= c || dis[x][y] <= z || dis[a][x] + dis[b][y] + 2 <= c + z || dis[a][y] + dis[b][x] + 2 <= c + z) {
            cout << "YES" << ok;
        }
        else {
            cout << "NO" << ok;
        }
    }
}