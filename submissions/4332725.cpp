#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ok "\n"

const int MN = 2005;
int n, m, a, b, dis[MN];
bool vis[MN];
vector<int> adj[MN];


int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q; q.push(a);
    vis[a] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int neighbour : adj[cur]) {
            if (vis[neighbour]) continue;
            q.push(neighbour);
            vis[neighbour] = 1;
            dis[neighbour] = dis[cur] + 1;
        }
    }
    if (vis[b]) cout << "GO SHAHIR!" << ok;
    else cout << "NO SHAHIR!" << ok;
}