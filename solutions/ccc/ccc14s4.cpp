// ccc14s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ok "\n"

const int MN = 1005;

struct ww {
    int l, t, r, b, v;
};

int n, t, d[2 * MN][2 * MN];
long long out;
map<int, int> cx, cy;
vector<int> rx, ry;
ww w[MN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> w[i].l >> w[i].t >> w[i].r >> w[i].b >> w[i].v;
        cx[w[i].l] = cx[w[i].r] = cy[w[i].t] = cy[w[i].b] = 0;
    }
    int cnt = 0;
    for (auto &x : cx) {
        x.second = ++cnt;
        rx.push_back(x.first);
    }
    cnt = 0;
    for (auto &y : cy) {
        y.second = ++cnt;
        ry.push_back(y.first);
    }
    for (int i = 0; i < n; i++) {
        int l = cx[w[i].l], t = cy[w[i].t], r = cx[w[i].r], b = cy[w[i].b], v = w[i].v;
        d[l][t] += v;
        d[l][b] -= v;
        d[r][t] -= v;
        d[r][b] += v;
    }
    for (int i = 1; i < cx.size(); i++) {
        for (int j = 1; j < cy.size(); j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (d[i][j] >= t) {
                out += 1LL * (rx[i] - rx[i - 1]) * (ry[j] - ry[j - 1]);
            }
        }
    }
    cout << out << ok;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file