// sac22cc5p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 1e6 + 5;
int n, q;
vector<pi> a, b;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({ x, y });
    }
    sort(a.begin(), a.end());
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i].first <= b.back().second + 1) {
            b.back().second = max(b.back().second, a[i].second);
        }
        else {
            b.push_back(a[i]);
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        int p = upper_bound(b.begin(), b.end(), pi{ x, 2e9 }) - b.begin() - 1;
        if (p > -1 && b[p].second >= y) {
            cout << "Y" << ok;
        }
        else {
            cout << "N" << ok;
        }
    }
}