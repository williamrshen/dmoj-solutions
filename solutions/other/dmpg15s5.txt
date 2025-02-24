// dmpg15s5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"

const int MN = 10005;
int n, m, out;
short dif[MN][MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        x++; y++;
        dif[x][y] ++;
        dif[x][y + h] ++;
        dif[x + w][y] --;
        dif[x + w][y + h] ++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
            if (dif[i][j] % 2 != 0) {
                out++;
            }
        }
    }
    cout << out << ok;
}