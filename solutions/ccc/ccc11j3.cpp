#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

#define speed cin.tie(0); cin.sync_with_stdio(0);
#define int long long
#define pi pair<int, int>

int x, y;

int solve(int l, int r) {
    if (l - r < 0) {
        return 1;
    }
    else {
        l -= r;
        return solve(r, l) + 1;
    }
}

signed main() {
    speed

    cin >> x >> y;
    cout << solve(x,  y) + 1 << "\n";

    return 0;
}