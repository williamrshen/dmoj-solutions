#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ok "\n"

struct edge {
    int a, b, w;
    bool operator<(edge const& o) {
        return w > o.w;
    }
};

const int MN = 100005;
int n, k, out, par[MN];
edge e[MN];

int find(int x) {
    if (x != par[x]) {
        par[x] = find(par[x]);
    }
    return par[x];
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> e[i].b >> e[i].w;
        e[i].a = i;
        par[i] = i;
    }
    sort(e + 1, e + n + 1);
    long long out = 0;
    for (edge x : e) {
        int a = find(x.a), b = find(x.b);
        if (a != b) {
            par[a] = b;
            out += x.w;
        }
    }
    cout << out << ok;
}