#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 500005;
int n, f[MN], arr[MN];

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        f[arr[i]] ++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0LL, f[arr[i]] - 1);
        for (int j = 2 * arr[i]; j < MN; j += arr[i]) {
            ans += f[j];
        }
    }
    cout << ans << ok;
}