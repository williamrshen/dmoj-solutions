#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <math.h>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 2005;
int m;


signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> m;
    double ans1 = ((5 - sqrt(25 - 48 * (1 - m))) / 24);
    double ans = ((5 + sqrt(25 - 48 * (1 - m))) / 24);
    cout << fixed << setprecision(9) << max(ans1, ans) << ok;
}