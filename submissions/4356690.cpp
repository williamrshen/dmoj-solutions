#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <set>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 100005;
int n, k, t[MN], r, in[MN], x;
bool vis[MN];
vector<int> adj[MN];
int dp[MN];

int calc(int x) {
    if (dp[x] != -1) return dp[x];
    int ret = 0;
    for (int k : adj[x]) {
        ret = max(ret, calc(k));
    }
    return dp[x] = ret + t[x];
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    fill(dp, dp + MN, -1);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> r;
        for (int j = 1; j <= r; j++) {
            cin >> x;
            adj[x].push_back(i);
            in[i] ++;
        }
    }
    fill(vis, vis + MN, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int x : adj[c]) {
            if (!vis[x]) {
                in[x] --;
                if (in[x] == 0) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] > 0) {
            dp[i] = -2;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, calc(i));
       // cout << i << " " << dp[i] << ok;
    }
    cout << ans << ok;
}