#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b;
vector<int> adj[2005];
bool vis[2005];
int dis[2005];

int main() {
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(a);
    vis[a] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int x : adj[cur]) {
            if (!vis[x]) {
                vis[x] = true;
                q.push(x);
                dis[x] = dis[cur] + 1;
            }
        }
    }
    if (vis[b]) {
        cout << "GO SHAHIR!\n";
    }
    else {
        cout << "NO SHAHIR!\n";
    }
}