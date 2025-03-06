#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define pii pair<pi, int>

const int MN = 200005, INF = 0x3f3f3f3f;
int n, arr[MN], dp[MN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp + MN, INF);
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    for (int i = 2; i < n; i++) {
        for (int j = 1; j <= 2; j++) {
            dp[i] = min(dp[i], abs(arr[i] - arr[i - j]) + dp[i - j]);
        }
    }
    for (int i = 0; i < n; i++) {
       // cout << dp[i] << ok;
    }
    cout << dp[n - 1] << ok;
}