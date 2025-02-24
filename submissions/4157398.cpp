#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

#define ok "\n"

int d, x, c[32], dp[5285];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> d;
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> c[i];
    }
    fill(begin(dp), end(dp), 999999);
    dp[0] = 0;
    for (int i = 0; i <= d; i++) {
        for (int k = 0; k < x; k++) {
            if (i - c[k] >= 0) {
                dp[i] = min(dp[i], dp[i - c[k]] + 1);
            }
        }
    }
    if (dp[d] == 999999) cout << "Roberta acknowledges defeat." << ok;
    else cout << "Roberta wins in " << dp[d] << " strokes." << ok;
}