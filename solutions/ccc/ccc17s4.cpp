#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

#define ok "\n"

struct edge {
    int b, e, w, x;
    int operator<(edge const& o) {
        if (w != o.w) return w < o.w;
        return x < o.x;
    }
};


const int MM = 200005, MN = 100005;
int n, m, d, a, b, c, out, par[MN];
vector<edge> e;

int find(int a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}

bool merge(int a, int b) {
    if (find(a) != find(b)) {
        par[find(a)] = find(b);
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (i < n - 1) e.push_back({ a, b, c, 0 });
        else e.push_back({ a, b, c, 1 });
    }
    sort(e.begin(), e.end());
    //for (int i = 0; i < m; i++) {
    //    cout << e[i].b << " " << e[i].e << " " << e[i].w << ok;
    //}
    for (int i = 0; i <= n; i++) par[i] = i;
    int idx, cnt = 0, l = 0;
    for (idx = 0; idx <= m; idx++) {
        if (cnt == n - 1) break;
        if (merge(e[idx].b, e[idx].e)) {
            cnt++;
            l = e[idx].w;
            if (e[idx].x) out++;
        }
    }
    if (e[idx - 1].x) {
        for (int i = 0; i <= n; i++) par[i] = i;
        for (auto y : e) {
            if (find(y.b) != find(y.e)) {
                if (y.w < l || (y.w == l && !y.x)) merge(y.b, y.e);
                else if (!y.x && y.w <= d) {
                    cout << out - 1 << ok;
                    return 0;
                }
            }
        }
    }
    cout << out << ok;
    return 0;
}