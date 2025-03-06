#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

#define ok "\n"

const int INF = 0x3f3f3f3f;
int n;
ll ans = 0;
vector<int> f;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f.push_back(x);
    }
    sort(f.begin(), f.end());
    for (int i = 1; i < n; i++) {
        ans += f[0] + f[i];
    }
    cout << ans << ok;
}