// ccc21s5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int MN = 2e5 + 5;
int n, m, arr[MN], x[MN], y[MN], z[MN], dif[MN][17];

struct node {
    int l, r, g;
} st[4 * MN];

void build(int l, int r, int v) {
    st[v].l = l;
    st[v].r = r;
    if (l == r) {
        st[v].g = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * v);
    build(mid + 1, r, 2 * v + 1);
    st[v].g = gcd(st[2 * v].g, st[2 * v + 1].g);
}

int qry(int l, int r, int v) {
    if (st[v].l == l && st[v].r == r) {
        return st[v].g;
    }
    int mid = (st[v].l + st[v].r) / 2;
    if (r <= mid) {
        return qry(l, r, 2 * v);
    }
    if (l > mid) {
        return qry(l, r, 2 * v + 1);
    }
    return gcd(qry(l, mid, 2 * v), qry(mid + 1, r, 2 * v + 1));
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int k = 1; k <= m; k++) {
        cin >> x[k] >> y[k] >> z[k];
        dif[x[k]][z[k]] ++;
        dif[y[k] + 1][z[k]] --;
    }
    for (int i = 1; i <= n; i++) {
        int v = 1;
        for (int j = 1; j <= 16; j++) {
            dif[i][j] += dif[i - 1][j];
            if (dif[i][j] > 0) {
                v = lcm(v, j);
            }
        }
        arr[i] = v;
    }
    build(1, n, 1);
    for (int i = 1; i <= m; i++) {
        if (qry(x[i], y[i], 1) != z[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " \n"[i == n];
    }
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