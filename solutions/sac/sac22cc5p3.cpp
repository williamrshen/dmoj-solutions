// sac22cc5p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

const int MOD = 1e9 + 7, MV = 1e6 + 5;
int t, n;
long long ans[MV + 5];

void p() {
    ans[0] = 1;
    ans[1] = 0;
    for (int i = 2; i < MV; i++) {
        ans[i] = (i - 1) * (ans[i - 1] % MOD + ans[i - 2] % MOD) % MOD;
        ans[i] %= MOD;
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    p();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << ok;
    }
}