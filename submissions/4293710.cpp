#include <iostream>

using namespace std;

#define ok "\n"

int x, n, c[105], dp[10005];

int main() {
    cin >> x >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    fill(begin(dp), end(dp), 9999999);
    dp[0] = 0;
    for (int i = 1; i < 10005; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout << dp[x] << ok;
}