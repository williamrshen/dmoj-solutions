#include <iostream>
#include <array>
#include <string>

using namespace std;

#define ok "\n"

const int MN = 55;
int t, n, k, out = 0, dir[2][2] = { {0,1},{1,0} };
string grid[MN];

void solve(int r, int c, int d, int a) {
    if (r == n - 1 && c == n - 1) {
        out++;
        return;
    }
    for (int i = 0; i < 2; i++) {
        int nr = r + dir[i][0], nc = c + dir[i][1], nk = a + (i != d);
        if (nr >= n || nc >= n || grid[nr][nc] == 'H' || nk > k) continue;
        solve(nr, nc, i, nk);
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t;
    for (int j = 0; j < t; j++) {
        out = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        solve(0, 0, -1, -1);
        cout << out << ok;
    }
}