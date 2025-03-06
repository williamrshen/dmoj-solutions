// wc07p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 16, MOD = 13371337;
int t, n, dp[MN][1 << MN];
vector<int> adj[MN];

int solve(int x, int msk) {
    if (x == n - 1) {
        return 1;
    }
    if (dp[x][msk] != -1) {
        return dp[x][msk];
    }
    int ret = 0;
    for (int k : adj[x]) {
        if ((msk >> k & 1) == 0) {
            ret += solve(k, msk | 1 << k);
            ret %= MOD;
        }
    }
    return dp[x][msk] = ret;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x; cin >> x;
                if (x) {
                    adj[i].push_back(j);
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 1) << ok;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }
}