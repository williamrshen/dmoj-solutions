#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

#define ok "\n"
#define int long long

int q, a, b, c;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        cout << b * a + c % a << ok;
    }
}