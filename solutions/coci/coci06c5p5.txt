#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ok "\n"

const int MN = 205;
int n, arr[MN], dp[MN][MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = dp[i + n][i + n] = arr[i] % 2;
    }
    for (int sz = 1; sz <= n; sz++) {
        for (int l = 1; l + sz <= 2 * n; l++) {
            int r = l + sz;
            dp[l][r] = max(dp[l][l] - dp[l + 1][r], dp[r][r] - dp[l][r - 1]);
        }
    }
    int out = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][i] - dp[i + 1][i + n - 1] > 0) {
            out++;
        }
    }
    cout << out << ok;
}