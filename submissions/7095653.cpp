#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;
vector<int> adj[2005];
bool vis[2005];

void dfs(int source) {
    if (vis[source]) {
        return;
    }
    else {
        vis[source] = true;
        for (auto x : adj[source]) {
            dfs(x);
        }
    }
}

int main() {
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(a);
    if (vis[b]) {
        cout << "GO SHAHIR!\n";
    }
    else {
        cout << "NO SHAHIR!\n";
    }
}