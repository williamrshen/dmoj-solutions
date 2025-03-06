#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, u, v, c, m = 0;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // int one[n + 1]; int two[n + 1];
    vector<int> one; vector<int> two;
    for (int i = 0; i < n + 1; i ++) {
      one.push_back(0); two.push_back(0);
    }

    queue<int> q; 
    q.push(1);
    int d[n + 1];
    memset(d, -1, sizeof(d)); 
    d[1] = 1;
    while (!q.empty()) {
        c = q.front(); q.pop();
        for (int x : adj[c]) {
            if (d[x] == -1) {
                d[x] = d[c] + 1;
                q.push(x);
                if (d[x] > d[m]) m = x;
            }
        }
    }

    q.push(m);
    memset(d, -1, sizeof(d));
    d[m] = 1;
    while (!q.empty()) {
        c = q.front(); q.pop();
        for (int x : adj[c]) {
            if (d[x] == -1) {
                d[x] = d[c] + 1;
                q.push(x);
                one[x] = d[x];
                if (d[x] > d[m]) m = x;
            }
        }
    }

    q.push(m);
    memset(d, -1, sizeof(d));
    d[m] = 1;
    while (!q.empty()) {
        c = q.front(); q.pop();
        for (int x : adj[c]) {
            if (d[x] == -1) {
                d[x] = d[c] + 1;
                q.push(x);
                two[x] = d[x];
                if (d[x] > d[m]) m = x;
            }
        }
    }


    for (int i = 1; i <= n; i ++) {
        cout << max(one[i], two[i]) << endl;
    }

}