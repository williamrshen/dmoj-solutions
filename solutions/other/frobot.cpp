// ccc00s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

#define ok "\n"

int n, k, j, holes[1000005], moves[105], dp[1000005];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k >> j;
    for (int i = 0; i < k; i++) {
        cin >> holes[i];
    }
    for (int i = 0; i < j; i++) {
        cin >> moves[i];
    }
    fill(begin(dp), end(dp), 999999);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        dp[holes[i]] = -1;
    }
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < j; k++) {
            if (i - moves[k] >= 0) {
                if (dp[i - moves[k]] == -1) continue;
                dp[i] = min(dp[i], dp[i - moves[k]] + 1);
            }
        }
    }
    if (dp[n] == 999999) cout << -1 << ok;
    else cout << dp[n] << ok;
}