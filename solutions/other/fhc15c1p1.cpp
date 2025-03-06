#include <bits/stdc++.h>
#define speedy ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std; 

int t, a, b, k, p[10000005], out = 0;

void s () {
    for (int i = 2; i < 10000005; i ++) {
        if (p[i] == 0) {
            for (int j = i; j < 10000009; j += i) {
                p[j] ++;
            }
        }
    }
}

signed main() {
    speedy
    s();
    cin >> t;
    for (int i = 1; i <= t; i ++) {
        out = 0;
        cin >> a >> b >> k;
        for (int j = a; j <= b; j ++) {
            if (p[j] == k) out ++;
        }
        cout << "Case #" << i << ": " << out << "\n";
    }
}