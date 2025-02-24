// usaco22opens3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ok "\n"

const int MN = 200005;
int q, psa[3][MN];
string s;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> s >> q;
    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == 'C') {
            psa[0][i] = psa[0][i - 1] + 1;
            psa[1][i] = psa[1][i - 1];
            psa[2][i] = psa[2][i - 1];
        }
        if (s[i - 1] == 'O') {
            psa[0][i] = psa[0][i - 1];
            psa[1][i] = psa[1][i - 1] + 1;
            psa[2][i] = psa[2][i - 1];
        }
        if (s[i - 1] == 'W') {
            psa[0][i] = psa[0][i - 1];
            psa[1][i] = psa[1][i - 1];
            psa[2][i] = psa[2][i - 1] + 1;
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        int c = psa[0][r] - psa[0][l - 1];
        int o = psa[1][r] - psa[1][l - 1];
        int w = psa[2][r] - psa[2][l - 1];
        c += w; o += w;
        if (c % 2 != 0 && o % 2 == 0) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }
}