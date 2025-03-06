#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define ok "\n"

const int MAXN = 1e5 + 5, LOG = 17;
int n, a, b, w, q, dep[MAXN];
int bl[MAXN][LOG], l1[MAXN][LOG], l2[MAXN][LOG];
vector<pair<int, int>> adj[MAXN];

int solve(int a, int b) {
    vector<int> l;
    if (dep[b] > dep[a]) swap(b, a);
    for (int i = LOG - 1; i >= 0; i--) {
        if (dep[a] - (1 << i) >= dep[b]) {
            l.push_back(l1[a][i]);
            l.push_back(l2[a][i]);
            a = bl[a][i];
        }
    }
    sort(l.begin(), l.end(), greater<int>());
    if (a == b) return l[1];
    for (int i = LOG - 1; i >= 0; i--) {
        if (bl[a][i] != bl[b][i]) {
            l.push_back(l1[a][i]), l.push_back(l2[a][i]), l.push_back(l1[b][i]), l.push_back(l2[b][i]);
            a = bl[a][i], b = bl[b][i];
        }
    }
    l.push_back(l1[a][0]), l.push_back(l2[a][0]), l.push_back(l1[b][0]), l.push_back(l2[b][0]);
    sort(l.begin(), l.end(), greater<int>());
    return l[1];
}

void dfs(int c, int p, int d, int w) {
    dep[c] = d;
    bl[c][0] = p;
    l1[c][0] = w;
    l2[c][0] = -1;
    for (int i = 1; i < LOG; i++) {
        bl[c][i] = bl[bl[c][i - 1]][i - 1];
        l1[c][i] = max(l1[c][i - 1], l1[bl[c][i - 1]][i - 1]);
        l2[c][i] = -1;
        int s = min(l1[c][i - 1], l1[bl[c][i - 1]][i - 1]);
        l2[c][i] = max(max(max(l2[c][i], s), l2[c][i - 1]), l2[bl[c][i - 1]][i - 1]);
    }
    for (auto x : adj[c]) {
        if (x.first != p) dfs(x.first, c, d + 1, x.second);
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    dfs(1, 0, 0, 0);
    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << solve(a, b) << ok;
    }
}