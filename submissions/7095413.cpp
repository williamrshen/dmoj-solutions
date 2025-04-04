#include <iostream>
#include <queue>

using namespace std;


int sr, sc, er, ec;
int dis[10][10];
bool vis[10][10];

int main() {
    cin >> sr >> sc >> er >> ec;

    queue<pair<int, int>> q;
    q.push({ sr, sc });
    vis[sr][sc] = true;

    int move[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1}, {1, -2 }, {1,2}, {-1, -2}, {-1, 2} };

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = cr + move[i][0];
            int nc = cc + move[i][1];
            if (nr < 1 || nr > 8 || nc < 1 || nc > 8 || vis[nr][nc]) {
                continue;
            }
            q.push({ nr, nc });
            dis[nr][nc] = dis[cr][cc] + 1;
            vis[nr][nc] = true;
        }
    }
    cout << dis[er][ec] << "\n";
}