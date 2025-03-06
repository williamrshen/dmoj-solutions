#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <set>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 7005, INF = 0x3f;
int a, b, n, dp[MN];
bool mo[MN];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> a >> b >> n;
    mo[0] = 1;
    mo[990] = 1;
    mo[1010] = 1;
    mo[1970] = 1;
    mo[2030] = 1;
    mo[2940] = 1;
    mo[3060] = 1;
    mo[3930] = 1;
    mo[4060] = 1;
    mo[4970] = 1;
    mo[5030] = 1;
    mo[5990] = 1;
    mo[6010] = 1;
    mo[7000] = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mo[x] = 1;
    }
    dp[0] = 1;
    for (int i = 1; i < MN; i++) {
        if (!mo[i]) continue;
        for (int j = a; j <= b; j++) {
            if (i - j < 0) continue;
            else {
                if (!mo[i - j]) continue;
                else {
                    dp[i] += dp[i - j];
                }
            }
        }
    }
    cout << dp[7000] << ok;
}