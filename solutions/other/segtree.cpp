#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <set>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 100005, INF = 0x3f3f3f3f;
int n, m, x, y, arr[MN], t[4 * MN];
char q;

void build(int l, int r, int idx) {
    if (l == r) t[idx] = arr[l];
    else {
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
    }
}

int solve(int ql, int qr, int l, int r, int idx) {
    if (ql > qr) return INF;   // unncessary call
    if (ql <= l && qr >= r) return t[idx];
    else {
        int mid = (l + r) / 2;
        int left = solve(ql, min(mid, qr), l, mid, idx * 2);
        int right = solve(max(ql, mid + 1), qr, mid + 1, r, idx * 2 + 1);
        return min(left, right);
    }
}

void upd(int l, int r, int cidx, int cval, int idx) {
    if (l == r) t[idx] = cval;
    else {
        int mid = (l + r) / 2;
        if (cidx <= mid) {
            upd(l, mid, cidx, cval, idx * 2);
        }
        else {
            upd(mid + 1, r, cidx, cval, idx * 2 + 1);
        }
        t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    // fill(t, t + 4 * MN, INF);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, n, 1);
    while (m--) {
        cin >> q >> x >> y;
        if (q == 'M') {
            x++;
            upd(1, n, x, y, 1);
        }
        else {
            x++; y++;
            int ans = solve(x, y, 1, n, 1);
            cout << ans << ok;
        }
    }
}