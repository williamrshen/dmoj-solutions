#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, a;

signed main() {
    cin.tie(0), cin.sync_with_stdio(0);
    cin >> n;
    while (n --) {
        cin >> a;
        while (a % 2 == 0) a /= 2;
        if (a == 0 || a == 1) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}