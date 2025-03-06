#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 105;
int n, k, out, a[MN];
vector<int> adj[MN];

bool dfs(int x) {
    if (a[x] > 0) {
        return a[x]--;
    }
    if (a[x] == 0 && adj[x].size() == 0) {
        return 0;
    }
    for (int k : adj[x]) {
        if (!dfs(k)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int l, m; cin >> l >> m;
        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            adj[l].push_back(x);
        }
    }
    while (dfs(n)) {
        out++;
    }
    cout << out;
}