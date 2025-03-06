#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 1005;
int c, m, n, k, dp[MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> c >> m;
    for (int i = 1; i <= c; i++) {
        cin >> n >> k;
        for (int j = m; j >= k; j--) {
            dp[j] = max(dp[j], dp[j - k] + n);
        }
    }
    cout << dp[m] << ok;
}