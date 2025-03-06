// gfssoc3s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 105, MOD = 1e9 + 7;
int r, c, dp[MN][1 << 13];
vector<int> a;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> r >> c;
    for (int msk = 0; msk < 1 << c - 2; msk++) {
        if ((msk & msk >> 1) == 0 && (msk & msk >> 2) == 0) {
            a.push_back(msk);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < r; i++) {
        for (int k = 0; k < a.size(); k++) {
            for (int j = 0; j < a.size(); j++) {
                int msk = a[j] | a[j] << 1 | a[j] >> 1;
                if ((msk & a[k]) != 0) {
                    continue;
                }
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += dp[r - 1][i];
        ans %= MOD;
    }
    cout << ans - 1 << ok;
}