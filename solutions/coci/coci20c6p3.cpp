// coci20c6p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

#define ok "\n"
#define ll long long

const int MN = 2005, MOD = 1e9 + 7;
int n, k;
ll f[MN], inv[MN], dp[MN], w[MN];
unordered_map<string, int> mp;
string s;

ll fpow(ll b, ll p) {
    int ret = 1;
    for (; p; p >>= 1, b = b * b % MOD) {
        if (p & 1) {
            ret = ret * b % MOD;
        }
    }
    return ret;
}

ll c(int n, int k) {
    return f[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void run() {
    f[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = i * f[i - 1] % MOD;
    }
    for (int i = 1; i <= n; i++) {
        inv[i] = fpow(f[i], MOD - 2);
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    run();
    for (int i = 0; i < n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        mp[s] ++;
    }
    dp[0] = 1;
    for (auto &x : mp) {
        int f = x.second;
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= f; i++) {
            int p = i * (i - 1) / 2;
            ll v = c(f, i);
            for (int j = k; j >= p; j--) {
                w[j] = (w[j] + dp[j - p] * v % MOD) % MOD;
            }
        }
        for (int i = 0; i <= k; i++) {
            dp[i] = (dp[i] + w[i]) % MOD;
        }
    }
    cout << dp[k] << ok;
}