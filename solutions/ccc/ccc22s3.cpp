// ccc22s3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 1000005;
int n, m, k, ans[MN];

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> k; 
    if (n > k) {
        cout << -1 << ok;
        return 0;
    }
    ans[0] = m;
    int c = 1, l = 1;
    for (int i = 1; i <= n; i++) {
        int d = k - n + i;
        if (k == n - i + 1) {
            ans[i] = ans[i - 1];
            k--;
        }
        else if (d <= min(i, m)) {
            ans[i] = ans[i - d];
            k -= d;
        }
        else {
            ans[i] = c;
            k -= l;
            c++; l++;
            if (c > m) c = 1;
            l = min(m, l);
        }
    }
    if (k) {
        cout << -1 << ok;
    }
    else {
        cout << ans[1];
        for (int i = 2; i <= n; i++) cout << " " << ans[i];
        cout << ok;
    }
}