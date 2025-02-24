#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ok "\n"

const int MN = 1000005;
int n, q, l, r, k, nxt[MN], pre[MN];

// pre[head] = 0, nxt[last] = n + 1

void run() {
    for (int i = 0; i < MN; i++) {
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
}

void out() {
    int cur = -1;
    for (int i = 1; i <= n; i++) {
        if (pre[i] == 0) {
            cur = i;
            break;
        }
    }
    while (nxt[cur] != n + 1) {
        cout << cur << " ";
        cur = nxt[cur];
    }
    cout << cur << ok;
}

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    run();
    cin >> n >> q;
    while (q--) {
        cin >> l >> r >> k;
        nxt[pre[l]] = nxt[r];
        pre[nxt[r]] = pre[l];

        nxt[r] = nxt[k];
        pre[nxt[k]] = r;
        nxt[k] = l;
        pre[l] = k;
    }
    out();
}