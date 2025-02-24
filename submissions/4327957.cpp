#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ok "\n"

const int X = 131, MOD = 1e9 + 7;
string a, b;

int pow (int b, int p) {
    if (p == 0) return 1;
    else {
        int half = pow(b, p / 2);
        half %= MOD;
        if (p % 2 == 0) return half * half % MOD;
        else return half * half % MOD * b % MOD;
    }
}


signed main () {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> a >> b;
    int hashA = 0, hashB = 0, ans = 0;
    for (int i = 1; i <= min(a.size(), b.size()); i ++) {
        hashA += a[a.size() - i] * pow(X, i - 1);
        hashB *= X;
        hashB += b[i - 1];
        hashA %= MOD; hashB %= MOD;
        if (hashA == hashB) {
            ans = i;
        }
    }

    cout << a << b.substr(ans) << ok;
}