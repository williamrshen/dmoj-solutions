// olyquiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 1e5 + 5;
int n, a, b, c;
vector<pi> adj[MN];
bool out[MN];

void solve(int cur, int par, bool s) {
    out[cur] = s;
    for (auto x : adj[cur]) {
        if (x.first == par) {
            continue;
        }
        if (x.second % 2 == 0) {
            solve(x.first, cur, s);
        }
        else {
            solve(x.first, cur, !s);
        }
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    solve(1, -1, 0);
    for (int i = 1; i <= n; i++) {
        cout << out[i] << " ";
    }
}