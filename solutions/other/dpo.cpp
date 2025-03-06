// dpo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 22, MOD = 1e9 + 7;
int n, a[MN][MN], dp[1 << MN];

int solve(int i, int msk) {
    if (i == n) {
        return 1;
    }
    if (dp[msk] != -1) {
        return dp[msk];
    }
    int ret = 0;
    for (int j = 0; j < n; j++) {
        if ((msk >> j & 1) == 0 && a[i][j] == 1) {
            ret = (ret + solve(i + 1, msk | 1 << j)) % MOD;
        }
    }
    return dp[msk] = ret;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    fill(dp, dp + (1 << MN), -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve(0, 0) << ok;
}