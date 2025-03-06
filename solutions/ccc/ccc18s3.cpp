#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 105, INF = 0x3f3f3f3f;
int n, m, sr, sc, dis[MN][MN];
bool vis[MN][MN];
char g[MN][MN];
vector<pi> cam;
queue<pi> q;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void qq(int nr, int nc, int d) {
    if (g[nr][nc] != 'W' && !vis[nr][nc] && dis[nr][nc] > d) {
        q.push({ nr, nc });
        dis[nr][nc] = d;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                sr = i; sc = j;
                g[i][j] = '.';
            }
            if (g[i][j] == 'C') cam.push_back({ i, j });
        }
    }
    for (auto c : cam) {
        for (int k = 0; k < 4; k++) {
            int nr = c.first, nc = c.second;
            while (1) {
                nr += dir[k][0];
                nc += dir[k][1];
                if (g[nr][nc] == 'W') break;
                if (g[nr][nc] == '.') vis[nr][nc] = 1;
            }
        }
    }
    memset(dis, INF, sizeof(dis));
    if (!vis[sr][sc]) {
        q.push({ sr, sc });
        dis[sr][sc] = 0;
    }
    while (q.size()) {
        auto c = q.front(); q.pop();
        int cr = c.first, cc = c.second;
        if (g[cr][cc] == '.') {
            for (int i = 0; i < 4; i++) {
                int nr = cr + dir[i][0], nc = cc + dir[i][1];
                qq(nr, nc, dis[cr][cc] + 1);
            }
        }
        else if (g[cr][cc] == 'U') qq(cr - 1, cc, dis[cr][cc]);
        else if (g[cr][cc] == 'D') qq(cr + 1, cc, dis[cr][cc]);
        else if (g[cr][cc] == 'L') qq(cr, cc - 1, dis[cr][cc]);
        else if (g[cr][cc] == 'R') qq(cr, cc + 1, dis[cr][cc]);
    }
    g[sr][sc] = 'S';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.') cout << (dis[i][j] == INF ? -1 : dis[i][j]) << ok;
        }
    }
}