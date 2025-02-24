//
// Created by ryan javid on 2021-12-22.
//

#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
char grid[MM][MM], X;
int vis[MM][MM], m, n, R[] = {0, -1, 0, 1}, C[] = {1, 0, -1, 0};
vector<int> ans;
int main() {
    memset(vis,0,sizeof vis);
    pair<int, int> s;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> X;
            grid[i][j] = X;
            if(X == '1') {
                s.first = i, s.second = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int x = cur.first; int y = cur.second;
        for(int i = 0; i < 4; i++) {
            int dx = x+R[i], dy = y+C[i];
            if(dx < 0 || dy < 0 || dx >= n || dy >= m) {
                continue;
            }
            if(grid[dx][dy] == '#' || vis[dx][dy] == 1) {
                continue;
            }
            if(isdigit(grid[dx][dy])) {
                ans.push_back((int)grid[dx][dy]);
                q.emplace(dx,dy);
                vis[dx][dy] = 1;
            } else {
                q.emplace(dx,dy);
                vis[dx][dy] = 1;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << 1 << " ";
    for(auto i : ans) {
        cout << i - 48<< " ";
    }
}