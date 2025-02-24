// oly18novp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 1e6 + 5;
int n, out;
vector<pi> a;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({ y, x });
    }
    sort(a.begin(), a.end());
    int t = 0;
    for (auto x : a) {
        if (x.second >= t) {
            out++;
            t = x.first;
        }
    }
    cout << out;
}