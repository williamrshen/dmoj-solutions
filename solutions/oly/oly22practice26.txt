#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ok "\n"
#define pi pair<int, int>


const int MN = 200005;
int n, k, ans = 0;
vector<pi> f(MN);
set<int> s;


int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < MN; i++) {
        f[i].first = i;
        f[i].second = 0;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x].second++;
    }
    sort(f.begin(), f.end(),
        [](pi a, pi b) {
            return a.second > b.second;
        });
    for (int i = k; i < MN; i++) {
        ans += f[i].second;
    }
    cout << ans << ok;
}