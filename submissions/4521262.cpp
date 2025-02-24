#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 105;
int n, k, out, a[MN];
vector<int> adj[MN];
unsigned long long r[MN];

bool c(int x) {
    memset(r, 0, sizeof(r));
    r[n] = x;
    for (int i = n; i > 0; i--) {
        if (r[i] > a[i]) {
            unsigned long long ex = r[i] - a[i];
            if (ex > 0 && adj[i].size() == 0) {
                return 0;
            }
            for (int k : adj[i]) {
                r[k] += ex;
            }
        }
    }
    return 1;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int l, m; cin >> l >> m;
        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            adj[l].push_back(x);
        }
    }
    int l = a[n], r = 10000 * n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (c(m)) {
            out = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    cout << out;
}