// ioi98p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"

struct evt {
    int beg, end, loc, typ;
    bool operator<(evt const& o) {
        if (loc != o.loc) return loc < o.loc;
        else return typ < o.typ;
    }
};

const int pow10[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
const int MN = 20005;
int n, arr[MN];
vector<evt> hori, vert;

int sweep(vector<evt> x) {
    int ret = 0;
    for (auto e : x) {
        if (e.typ == 1) {
            for (int i = e.beg + pow10[4]; i < e.end + pow10[4]; i++) {
                if (arr[i] == 0) ret++;
                arr[i] ++;
            }
        }
        else {
            for (int i = e.beg + pow10[4]; i < e.end + pow10[4]; i++) {
                arr[i] --;
                if (arr[i] == 0) ret++;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        hori.push_back({ y1, y2, x1, 1 });
        hori.push_back({ y1, y2, x2, 2 });
        vert.push_back({ x1, x2, y1, 1 });
        vert.push_back({ x1, x2, y2, 2 });
    }
    sort(hori.begin(), hori.end());
    sort(vert.begin(), vert.end());
    int vsweep = sweep(vert);
    fill(arr, arr + MN, 0);
    int hsweep = sweep(hori);
    cout << vsweep + hsweep << ok;
}