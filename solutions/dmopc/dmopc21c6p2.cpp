#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 7005, INF = 0x3f3f3f3f;
int n, k, ans = 0;
string s;
vector<int> kek;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k >> s;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cur++;
        else {
            kek.push_back(cur);
            cur = 0;
        }
    }
    kek.push_back(cur);
    sort(kek.begin(), kek.end(), greater<int>());
    int upto = min(int(kek.size()), k);
    // cout << upto << ok;
    for (int i = 0; i < upto; i++) {
        ans += kek[i];
    }
    cout << ans << ok;
}