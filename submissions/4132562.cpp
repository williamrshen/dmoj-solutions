#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>

using namespace std;

#define speed cin.sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pi pair<int, int>

signed main() {
    speed

    int sr, sc, er, ec, cr, cc, nr, nc;
    cin >> sr >> sc >> er >> ec;
    int m[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2} };
    queue<pi> q; q.push({ sr, sc });
    int d[9][9]; bool v[9][9];
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    v[sr][sc] = 1; d[sr][sc] = 1;
    while (!q.empty()) {
        cr = q.front().first; cc = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i ++) {
            nr = cr + m[i][0];
            nc = cc + m[i][1];
            if (nr < 1 || nc < 1 || nr > 8 || nc > 8 || v[nr][nc]) continue;
            d[nr][nc] = d[cr][cc] + 1;
            v[nr][nc] = 1;
            q.emplace(nr, nc);
        }
    }
    cout << d[er][ec] - 1 << "\n";

    return 0;
}