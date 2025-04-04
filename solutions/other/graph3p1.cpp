#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<int> adj[30005];
bool vis[30005];
int dis[30005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        q.push(x);
        vis[x] = true;
    }
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
    int ans = 0;
    for (int i = 0; i < 30005;i++) {
        ans = max(ans, dis[i]);
    }
    cout << ans << "\n";
}