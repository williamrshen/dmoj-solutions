#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 1000000000000000005;
int l, r;

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i *= 2) {
        ans++;
    }
    cout << ans << ok;
}