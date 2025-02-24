#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c, t = 0, m = 0;
    cin >> n;
    vector<pair<int,int>> adj[n + 1];
    for (int i = 0; i < n; i ++) {
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
      t += c * 2;
    }
    queue<int> q;
    int d[n + 2];
    memset(d, -1, sizeof(d));
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
      c = q.front();
      q.pop();
      for (auto x : adj[c]) {
        if (d[x.first] == -1) {
          d[x.first] = d[c] + x.second;
          q.push(x.first);
          m = max(m, d[x.first]);
        }
      }
    }
    cout << t - m << "\n";
}