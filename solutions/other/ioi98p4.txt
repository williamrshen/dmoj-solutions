// ioi98p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define y1 aaaaaa

struct evt {
    int st, en, loc, t;
    // t=1 -> start, t=2 -> end
    bool operator<(evt const& o) {
        if (loc != o.loc) return loc < o.loc;
        return t < o.t;
    }
};

const int MN = 5005, MC = 20005, TENK = 10000;

int n, x1, y1, x2, y2, layers[MC];
vector<evt> vert, hori;

int solve(vector<evt> e) {
    int ret = 0;
    for (auto x : e) {
        if (x.t == 1) {
            for (int i = x.st; i < x.en; i++) {
                if (layers[i] == 0) {
                    ret++;
                }
                layers[i] ++;
            }
        }
        else {
            for (int i = x.st; i < x.en; i++) {
                layers[i] --;
                if (layers[i] == 0) {
                    ret++;
                }
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += TENK; y1 += TENK; x2 += TENK; y2 += TENK;
        vert.push_back({ y1, y2, x1, 1 });
        vert.push_back({ y1, y2, x2, 2 });
        hori.push_back({ x1, x2, y1, 1 });
        hori.push_back({ x1, x2, y2, 2 });
    }
    sort(vert.begin(), vert.end()); 
    sort(hori.begin(), hori.end());
    cout << solve(vert) + solve(hori) << ok;
}