#include <bits/stdc++.h>
#define speedy ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int mn = 5005;
string g[mn];

bool legit (int n, int m) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == '.') {
              continue;
            }
            else {
                if (g[i][j] != g[i][m - j - 1] && g[i][m - j - 1] != '.') {
                    return false;
                }
                else g[i][m - j - 1] = g[i][j];
            }
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (g[j][i] == '.') continue;
            else {
                if (g[j][i] != g[n - j - 1][i] && g[n - j - 1][i] != '.') {
                    return false;
                }
                else g[n - j - 1][i] = g[j][i];
            }
        }
    }
    return true;
}

signed main() {
    speedy
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        cin >> g[i];
    }
    if (!legit(n, m)) cout << -1 << "\n";
    else {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (g[i][j] == '.') {
                    g[i][j] = g[i][m - j - 1] = 'z';
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                cout << g[i][j];
            }
            cout << "\n";
        }
    }
}