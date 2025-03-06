#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

#define ok "\n"
#define int long long

const int MN = 1000005;
int n, k, ans[MN];

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        ans[i] = i;
    }
    ans[n] = -1 * ((n) * (n - 1) / 2) % k;
    while (ans[n] < n) {
        ans[n] += k;
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n] << ok;
}