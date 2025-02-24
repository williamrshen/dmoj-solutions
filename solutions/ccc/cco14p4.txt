// cco14p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define ok "\n"

struct hm {
    int f, c;
    bool operator<(hm const& o) {
        return c < o.c;
    }
};

const int MN = 1e6 + 5, MOD = 1e9 + 7;
int n, p, fu, cnt;
vector<hm> a;


int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        int f, c; cin >> f >> c;
        if (i == p) {
            fu = f;
            cnt = 1;
        }
        else if (f >= c) {
            a.push_back({ f, c });
        }
    }
    sort(a.begin(), a.end());
    for (auto x : a) {
        if (fu >= x.c) {
            fu = fu - x.c + x.f;
            cnt++;
        }
    }
    cout << fu << ok << cnt << ok;
}