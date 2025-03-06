#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 1000005;
int n, q, BIT[MN];

void upd(int l, int r, int x) {
    for (int i = l; i <= n; i += i & (-i)) {
        BIT[i] += x;
    }
    for (int i = r + 1; i <= n; i += i & (-i)) {
        BIT[i] -= x;
    }
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
        ret += BIT[i];
    }
    return ret;
}

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int o; cin >> o;
        if (o == 1) {
            int l, r, x; cin >> l >> r >> x;
            upd(l, r, x);
        }
        else {
            int x; cin >> x;
            cout << qry(x) << ok;
        }
    }

    for (int i = 1; i <= n; i++) {
        //cout << qry(i) << ok;
    }
}