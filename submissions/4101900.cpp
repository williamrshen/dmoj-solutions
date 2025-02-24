#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, q, x, y;
int p[100005];
char o;

int f (int x) {
    if (p[x] == x) return x;
    else return p[x] = f(p[x]);
}
void m (int x, int y) {
    x = f(x), y = f(y);
    if (x != y) p[x] = y;
}

signed main() {
    cin.tie(0), cin.sync_with_stdio(0);
    for (int i = 0; i < 100005; i ++) p[i] = i;
    cin >> n >> q;
    while (q --) {
        cin >> o >> x >> y;
        if (o == 'A') {
            m(x, y);
        }
        else {
            if (f(x) == f(y)) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}