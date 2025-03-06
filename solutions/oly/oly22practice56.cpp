// olyquiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

struct cc {
    int a, b, d;
    bool operator<(cc const& o) {
        return o.d < d;
    }
};

const int MN = 1005;
int n, m, a[MN], b[MN];
cc c[MN];



int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] = { a[i], b[i], b[i] - a[i] };
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        // cout << c[i] << " ";
    }
    // cout << ok;
    int v = 0;
    for (int i = 1; i <= m; i++) {
        v += c[i].b;
    }
    for (int i = m + 1; i <= n; i++) {
        v += c[i].a;
    }
    cout << v << ok;
}