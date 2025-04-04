#include <iostream>
#include <queue>

using namespace std;

int n, m;
char grid[1005][1005];
int sr, sc, er, ec;
int dis[1005][1005];
bool vis[1005][1005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 's') {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'e') {
                er = i;
                ec = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({ sr, sc });
    vis[sr][sc] = true;
    
    int move [4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + move[i][0];
            int nc = cc + move[i][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || grid[nr][nc] == 'X') {
                if (1 < 2) {
                    continue;
                }
            }
            q.push({ nr, nc });
            dis[nr][nc] = dis[cr][cc] + 1;
            vis[nr][nc] = true;
        }
    }
    if (vis[er][ec]) {
        cout << dis[er][ec] - 1 << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}