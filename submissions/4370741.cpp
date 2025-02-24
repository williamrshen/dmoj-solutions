// dmopc20c4p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define int long long

struct evt {
    int x, y, T;
    bool operator<(evt const& o) {
        if (x != o.x) {
            return x < o.x;
        }
        else return T < o.T;
    }
};

const int MN = 400005;
int n, m, t[MN * 4];
vector<int> ys;
int r[MN];
map<int, int> ycomp;
vector<evt> e;

void upd(int l, int r, int cval, int cidx, int idx) {
    if (l == r) t[idx] += cval;
    else {
        int mid = (l + r) / 2;
        if (cidx <= mid) upd(l, mid, cval, cidx, idx * 2);
        else upd(mid + 1, r, cval, cidx, idx * 2 + 1);
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }
}

int qry(int l, int r, int ql, int qr, int idx) {
    if (r < ql || l > qr) return 0;
    else if (ql <= l && qr >= r) return t[idx];
    else {
        int mid = (l + r) / 2;
        int left = qry(l, mid, ql, qr, idx * 2);
        int right = qry(mid + 1, r, ql, qr, idx * 2 + 1);
        return left + right;
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        e.push_back({ a, b, 2 });
        ys.push_back(b);
        r[i] = b;
    }
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        e.push_back({ a, b, 1 });
        ys.push_back(b);
    }
    sort(ys.begin(), ys.end()); ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int i = 0; i < ys.size(); i++) {
        ycomp[ys[i]] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        upd(1, ys.size(), 1, ycomp[r[i]], 1);
    }

    sort(e.begin(), e.end());
    int out = 0;
    
    for (evt x : e) {
        
        if (x.T == 1) {
            out += qry(1, ycomp.size(), 1, ycomp[x.y], 1);
        }
        else {
            upd(1, ycomp.size(), -1, ycomp[x.y], 1);
        }
    }
    cout << out << ok;
}