// ds1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define int long long

const int MN = 1e5 + 5;

int n, m, a[MN], f[MN], bit[MN];
char o;

void upd1(int pos, int val) {
    for (int i = pos; i < MN; i += i & -i) {
        bit[i] += val;
    }
}

void upd2(int pos, int val) {
    for (int i = pos; i < MN; i += i & -i) {
        f[i] += val;
    }
}

int qry1(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}
int qry2(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret += f[i];
    }
    return ret;
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd1(i, a[i]);
        upd2(a[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> o >> x;
        if (o == 'C') {
            cin >> y;
            upd1(x, -a[x] + y);
            upd2(a[x], -1);
            upd2(y, 1);
            a[x] = y;
        }
        else if (o == 'S') {
            cin >> y;
            cout << qry1(y) - qry1(x - 1) << "\n";
        }
        else {
            cout << qry2(x) << "\n";
        }
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