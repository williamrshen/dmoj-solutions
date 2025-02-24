#include <bits/stdc++.h>

using namespace std;

#define ok "\n"

const int X = 131, MOD = 1e9 + 7;
int r, c, k, dp[26][26];
bool f[26][26];

int main () {
    cin >> r >> c >> k;
    for (int i = 0; i < k; i ++) {
        int x, y; cin >> x >> y;
        f[x][y] = 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= c; j ++) {
            if (j == 1 && i == 1) { dp[i][j] = 1; continue; }
            if (i == 1) {
                if (f[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1];
            }
            if (j == 1) {
                if (f[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j];
            }
            if (j != 1 && i != 1) {
                if (f[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    // for (int i = 1; i <= r; i ++) {
    //     for (int j = 1; j <= c; j ++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << ok;
    // }
    cout << dp[r][c] << ok;
}