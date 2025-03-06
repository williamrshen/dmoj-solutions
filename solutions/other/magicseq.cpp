#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define ok "\n"

const int MN = 91;
int n;
long long dp[MN], s = 1;

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    dp[1] = 1; 
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        s += dp[i];
    }
    cout << s << ok;
}