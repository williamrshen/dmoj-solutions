#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long


const int MN = 100005;
int n, par[MN];
long long sz[MN];
set<string> u;
map<string, int> m;

int find(int x) {
    if (par[x] == x) return x;
    else {
        return par[x] = find(par[x]);
    }
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x != y) {
        par[x] = y;
        int t = sz[y] + sz[x];
        sz[y] = t;
        sz[x] = t;
    }
}


int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    for (int i = 0; i < MN; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    cin >> n;
    int c = 1;
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        if (u.count(a) == 0) {
            m[a] = c++;
            u.insert(a);
        }
        if (u.count(b) == 0) {
            m[b] = c++;
            u.insert(b);
        }
        merge(m[b], m[a]);
        cout << sz[par[m[a]]] << ok;
    }
}