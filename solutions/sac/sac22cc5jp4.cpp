// sac22cc5j.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ok "\n"

const int MN = 2 * 1e5 + 5;
int n, c, x, in[MN];
vector<int> adj[MN];
bool vis[MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        while (c--) {
            cin >> x;
            adj[x].push_back(i);
            in[i] ++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            vis[i] = 1;
            in[i] = -1;
            cout << i << " ";
        }
    }
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int k : adj[cur]) {
            if (!vis[k]) {
                in[k] --;
                if (in[k] == 0) {
                    q.push(k);
                    vis[k] = 1;
                    in[k] = -1;
                    cout << k << " ";
                }
            }
        }
    }
}