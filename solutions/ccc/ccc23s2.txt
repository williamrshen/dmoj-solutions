#include <iostream>
#include <cstring>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 5005;
int n, a[MN], out[MN];

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    fill(out, out + MN, 1e11);
    for (int i = 1; i <= n; i++) { // picking center at number
        int cur = 0;
        for (int j = 0; j <= n; j++) {
            if (i - j < 1 || i + j > n) break;
            cur += abs(a[i + j] - a[i - j]);
            out[2 * j + 1] = min(out[2 * j + 1], cur);
        }
    }
    for (int i = 1; i <= n; i++) { // center at i.5
        int cur = 0;
        for (int j = 0; j <= n; j++) {
            if (i - j < 1 || i + j + 1 > n) break;
            cur += abs(a[i + j + 1] - a[i - j]);
            // cout << cur << " " << (i + j + 1) - (i - j) + 1 << "\n";
            out[2 * j + 2] = min(out[2 * j + 2], cur);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << out[i] << " ";
    }
}