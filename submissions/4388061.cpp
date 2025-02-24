// JAC Contest 1 P6 - Chores List
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, t[4*1000006], f[4*1000006];

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
        f[v] = 1;
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
        f[v] = f[v*2] + f[v*2+1];
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > tr || r < tl) return 0;
    if (l <= tl && r >= tr) return t[v];
    ll tm = (tl + tr)/2;
    return query(v*2, tl, tm, l, min(r, tm))
            + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

ll queryfreq(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if (l > tr || r < tl) return 0;
    if (l <= tl && r >= tr) return f[v];
    ll tm = (tl + tr)/2;
    return queryfreq(v*2, tl, tm, l, min(r, tm), val)
            + queryfreq(v*2+1, tm+1, tr, max(l, tm+1), r, val);
}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
        t[v] += val;
        if(f[v] == 1 && t[v] <= 0) f[v] = 0;
        else if(t[v] > 0) f[v] = 1;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update(v*2, tl, tm, pos, val);
        else update(v*2+1, tm+1, tr, pos, val);
        t[v] = t[v*2] + t[v*2+1];
        f[v] = f[v*2] + f[v*2+1];
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    build(a, 1, 0, n-1);
    for(ll i=0, op, x, y; i<m; i++) {
        cin >> op >> x >> y;
        if(op == 1) update(1, 0, n-1, x-1, -y);
        if(op == 2) cout << max(0LL, query(1, 0, n-1, x-1, y-1)) << "\n";
        if(op == 3) cout << max(0LL, queryfreq(1, 0, n-1, x-1, y-1, 0)) << "\n";
    }
    return 0;
}