#include <iostream>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 100005, INF = 0x3f3f3f3f;
int n, q, arr[MN];
pi t[4 * MN]; // first is time, second is complete/incomplete

void build(int l, int r, int idx) {
    if (l == r) t[idx] = { arr[l], 1 };
    else {
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        t[idx] = { t[idx * 2].first + t[idx * 2 + 1].first, t[idx * 2].second + t[idx * 2 + 1].second};
    }
}

void upd(int l, int r, int cidx, int cval, int idx) {
    if (l == r) {
        t[idx].first += cval;
        if (t[idx].second == 1 && t[idx].first <= 0) {
            t[idx].second = 0;
        }
        else if (t[idx].first > 0) t[idx].second = 1;
    }
    else {
        int mid = (l + r) / 2;
        if (cidx <= mid) upd(l, mid, cidx, cval, idx * 2);
        else upd(mid + 1, r, cidx, cval, idx * 2 + 1);
        t[idx] = { t[idx * 2].first + t[idx * 2 + 1].first, t[idx * 2].second + t[idx * 2 + 1].second };
    }
}

int qry(int l, int r, int ql, int qr, int idx, int type) {
    if (type == 2) {
        if (r < ql || l > qr) return 0;
        else if (qr >= r && ql <= l) return t[idx].first;
        else {
            int mid = (l + r) / 2;
            int left = qry(l, mid, ql, min(qr, mid), idx * 2, 2);
            int right = qry(mid + 1, r, max(ql, mid + 1), qr, idx * 2 + 1, 2);
            return left + right;
        }
    }
    else {
        if (r < ql || l > qr) return 0;
        else if (qr >= r && ql <= l) return t[idx].second;
        else {
            int mid = (l + r) / 2;
            int left = qry(l, mid, ql, min(qr, mid), idx * 2, 3);
            int right = qry(mid + 1, r, max(ql, mid + 1), qr, idx * 2 + 1, 3);
            return left + right;
        }
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, n, 1);

    while (q--) {
        int o; cin >> o;
        if (o == 1) {
            int i, x; cin >> i >> x;
            upd(1, n, i, -x, 1);
        }
        else {
            int l, r; cin >> l >> r;
            cout << max(qry(1, n, l, r, 1, o), 0LL) << ok;
        }
    }

    return 0;
}