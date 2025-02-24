#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 7005, INF = 0x3f3f3f3f;
int n, w;
long long dp[105][100005];
pi items[105];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        items[i] = { a, b };
    }
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 100005; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else {
                if (j - items[i].first < 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i].first] + items[i].second);
            }
        }
    }
    cout << dp[n][w] << ok;
}