#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define ok "\n"

const int MN = 10005;
int n, m, in[MN];
vector<int> adj[MN];


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b] ++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (in[x] == 0) continue;
            in[x] --;
            if (in[x] == 0) {
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] > 0) {
            cout << "N" << ok;
            return 0;
        }
    }
    cout << "Y" << ok;
    return 0;
}