// cco16p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;

#define ok "\n"

const int MN = 11;
int n, g, a[MN][MN];
unordered_map<int, int> mp;
char c;
long long out;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> g;
    for (int k = 0; k < g; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c;
                a[i][j] = (c == 'R');
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < n; j++) {
                if (a[i][j]) {
                    a[i][j] ^= 1;
                    a[i + 1][j] ^= 1;
                    a[i][j + 1] ^= 1;
                    a[i + 1][j + 1] ^= 1;
                }
            }
        }
        int msk = 0;
        for (int i = 0; i < n; i++) {
            msk = msk << 1 | a[i][n - 1];
        }
        for (int i = 0; i < n; i++) {
            msk = msk << 1 | a[n - 1][i];
        }
        mp[msk] ++;
    }
    for (auto x : mp) {
        out += 1LL * x.second * (x.second - 1) / 2;
    }
    cout << out << ok;
}