// ucc21p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

int h1, w1, h2, w2;
bool dp[3][305][3][305], vis[3][305][3][305];

bool solve(int h1, int w1, int h2, int w2) {
    if (h1 == 1 && w1 == 1 && h2 == 1 && w2 == 1) {
        return 0;
    }
    if (vis[h1][w1][h2][w2]) {
        return dp[h1][w1][h2][w2];
    }
    vis[h1][w1][h2][w2] = 1;
    bool v = 0;
    for (int i = 1; i < w1; i++) {
        v |= !solve(h1, i, h1, w1 - i);
    }
    for (int i = 1; i < w2; i++) {
        v |= !solve(h2, i, h2, w2 - i);
    }
    if (h1 == 2) {
        v |= !solve(1, w1, 1, w1);
    }
    if (h2 == 2) {
        v |= !solve(1, w2, 1, w2);
    }
    for (int i = 1; i <= 10 && i < w1; i++) {
        v |= !solve(h1, w1 - i, h2, w2);
    }
    for (int i = 1; i <= 10 && i < w2; i++) {
        v |= !solve(h1, w1, h2, w2 - i);
    }
    if (h1 == 2) {
        v |= !solve(1, w1, h2, w2);
    }
    if (h2 == 2) {
        v |= !solve(h1, w1, 1, w2);
    }
    return dp[h1][w1][h2][w2] = v;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> h1 >> w1 >> h2 >> w2;
    cout << (solve(h1, w1, h2, w2) ? "W" : "L");
}