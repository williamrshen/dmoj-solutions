#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define int long long

const int X = 131, MOD = 1e9 + 7;
string s, t;


int pow(int a, int p) {
    if (p == 0) return 1;
    int h = pow(a, p / 2);
    if (p % 2 == 0) return h * h % MOD;
    else return h * h % MOD * a % MOD;
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> s >> t;
    int ht = 0, hs = 0, ans = 0;
    for (int i = 1; i <= min(s.size(), t.size()); i++) {
        ht = ht * X + t[i - 1];
        hs += pow(X, i - 1) * s[s.size() - i];
        ht %= MOD, hs %= MOD;
        if (hs == ht) {
            ans = i;
        }
    }
    cout << s << t.substr(ans) << ok;
}