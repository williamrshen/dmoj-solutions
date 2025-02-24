#include <bits/stdc++.h>
using namespace std;

int const mn = 200005, sq = 450;
int n, q, x, v, o, c = 1, num, out = 0;
int k[mn], dp[mn], blk[mn], nxt[mn];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> k[i];
    for (int i = 0; i < n; i += sq) {
        for (int j = min(n, i + sq) - 1; j >= i; j --) {
            blk[j] = c;
            if (j + k[j] >  min(n, i + sq) - 1) {
                dp[j] = 1; 
                nxt[j] = j + k[j];
            }
            else {
                dp[j] = dp[j + k[j]] + 1;
                nxt[j] = nxt[j + k[j]]; 
            }
        }
        c ++;
    }
    // for (int i = 0; i < 4; i ++) cout << dp[i] << " " << nxt[i] << "\n";
    cin >> q;
    while (q --) {
        cin >> o;
        if (o == 1) {
            out = 0;
            cin >> x;
            while (x < n) {
                out += dp[x];
                x = nxt[x];
            }
            cout << out << "\n";
        }
        else {
            cin >> x >> v;
            k[x] = v;
            num = blk[x];
            while (x >= 0 && blk[x] == num) {
                if (x + k[x] >= n || blk[x + k[x]] != blk[x]) {
                    dp[x] = 1;
                    nxt[x] = x + k[x];
                }
                else {
                    dp[x] = dp[x + k[x]] + 1;
                    nxt[x] = nxt[x + k[x]];
                }
                x --;
            } 
        }
    }
    return 0;
}