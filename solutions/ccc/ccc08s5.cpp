// ccc08s5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 31;
int n, a, b, c, d, m[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
bool dp[MN][MN][MN][MN];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int a = 0; a < MN; a++) {
        for (int b = 0; b < MN; b++) {
            for (int c = 0; c < MN; c++) {
                for (int d = 0; d < MN; d++) {
                    for (int k = 0; k < 5; k++) {
                        if (a >= m[k][0] && b >= m[k][1] && c >= m[k][2] && d >= m[k][3]) {
                            if (!dp[a - m[k][0]][b - m[k][1]][c - m[k][2]][d - m[k][3]]) {
                                dp[a][b][c][d] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    while (n--) {
        cin >> a >> b >> c >> d;
        cout << (dp[a][b][c][d] ? "Patrick" : "Roland") << ok;
    }
}