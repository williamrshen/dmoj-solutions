#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

#define ok "\n"

const int MN = 1000005;
int n, x, arr[MN], dp[MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    for (int k = 0; k < 5; k++) {
        fill(dp, dp + MN, MN); dp[0] = 0;
        cin >> x >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - arr[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }
        cout << dp[x] << ok;
    }
}