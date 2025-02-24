#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 1000005;


int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int t;  cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (((b - a) * (d - c)) > (a * c)) {
            cout << "YES" << ok;
        }
        else {
            cout << "NO" << ok;;
        }
    }
}