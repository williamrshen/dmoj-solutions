// dmopc21c8p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

typedef long long ll;

#define ok "\n"
#define int long long

const int MN = 1e6 + 5, MOD = 1e9 + 7;
int n, m, a[2][MN];
ll ans[2];

ll fpow(ll b, ll p) {
    if (p == 0) {
        return 1LL;
    }
    ll half = fpow(b, p / 2) % MOD;
    if (p % 2 == 0) {
        return half * half % MOD;
    }
    else {
        return half * half % MOD * b % MOD;
    }
}

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }
    for (int k = 0; k < 2; k++) {
        int mi = 2, mx = 2 * m, col = 0;
        for (int i = k; i < n; i += 2) {
            if (a[0][i] > 0 && a[1][i] > 0) {
                mi = max(mi, a[0][i] + a[1][i]);
                mx = min(mx, a[0][i] + a[1][i]);
            }
            else if (a[0][i] > 0) {
                mi = max(mi, a[0][i] + 1);
                mx = min(mx, a[0][i] + m);
            }
            else if (a[1][i] > 0) {
                mi = max(mi, a[1][i] + 1);
                mx = min(mx, a[1][i] + m);
            }
            else {
                col++;
            }
        }
        for (int s = mi; s <= mx; s++) {
            int cnt = min(s - 1, m) - max(s - m, 1LL) + 1;
            ans[k] = (ans[k] + fpow(cnt, col)) % MOD;
        }
    }
    cout << ans[0] * ans[1] % MOD << ok;
}