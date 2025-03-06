#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, arr[1000005], dp[1000005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for (int i = 2; i <= n; i ++) dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    cout << dp[n] << "\n";
    return 0;
}