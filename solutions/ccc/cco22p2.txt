// cco22p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 1e6 + 5;

int n, b1[MN], b2[MN], p1[MN], p2[MN], u[MN], lft[MN], rit[MN], buy[MN];
long long out;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b1[i];
        b2[i] = b1[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> p1[i];
        p2[i] = p1[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 1; i < n; i++) {
        int num = min(b1[i], p1[i]);
        b1[i] -= num;
        p1[i] -= num;
        num = min(u[i], p1[i]);
        p1[i] -= num;
        num = min(b1[i + 1], p1[i]);
        b1[i + 1] -= num;
        p1[i] -= num;
        if (p1[i] > 0) {
            cout << "NO" << ok;
            return 0;
        }
    }
    memcpy(b1, b2, sizeof(b1));
    memcpy(p1, p2, sizeof(p1));
    for (int i = 1; i < n; i++) {
        int num = min(b1[i], p1[i]);
        b1[i] -= num;
        p1[i] -= num;
        lft[i] = num;
        num = min(b1[i + 1], p1[i]);
        b1[i + 1] -= num;
        p1[i] -= num;
        rit[i] = num;
        out += p1[i];
        buy[i] = p1[i];
    }
    for (int i = n - 1; i > 0; i--) {
        if (buy[i] > u[i]) {
            int dif = buy[i] - u[i];
            buy[i] -= dif;
            lft[i] += dif;
            buy[i - 1] += dif;
            rit[i - 1] -= dif;
        }
    }
    cout << "YES" << ok << out << ok;
    for (int i = 1; i < n; i++) {
        cout << lft[i] << " " << buy[i] << " " << rit[i] << ok;
    }
}