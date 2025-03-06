#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ok "\n"

const int MN = 200005;
int n, c[MN], dp[MN][2][2], t[2][2];
vector<int> adj[MN];
string s;

void dfs(int cur, int par) {
    dp[cur][0][0] = 0;
    dp[cur][0][1] = c[cur];
    if (s[cur - 1] == 'Y') {
        dp[cur][1][0] = 0;
        dp[cur][1][1] = c[cur];
    }
    for (int x : adj[cur]) {
        if (x == par) continue;
        dfs(x, cur);
        memset(t, 0x3f, sizeof(t));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (k == 0 && j == 0) continue;
                        t[i | (k & l)][j] = min(t[i | (k & l)][j], dp[cur][i][j] + dp[x][k][l]);
                    }
                }
            }
        }
        memcpy(dp[cur], t, sizeof(t));
    }
}

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dfs(1, 0);
    cout << min(dp[1][1][0], dp[1][1][1]) << ok;
}