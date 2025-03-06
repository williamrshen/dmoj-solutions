#include <iostream>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 100005;
int n, w, a, b, dp[MN];


int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> w;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        for (int j = MN - 1; j >= b; j--) {
            dp[j] = min(dp[j], dp[j - b] + a);
        }
    }
    for (int i = MN - 1; i >= 0; i--) {
        if (dp[i] <= w) {
            cout << i << ok;
            return 0;
        }
    }
}