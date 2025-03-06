// comparingarrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"
#define ll long long

const int MN = 5e5 + 5, MOD = 1e9 + 7, X = 1e8 + 7;
int n, q, a[MN];
ll bit[MN], pw[MN];

void upd(int idx, int val) {
    for (int i = idx; i < MN; i += i & -i) {
        bit[i] = (bit[i] + val) % MOD;
    }
}

int qry(int x) {
    ll ret = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ret = (ret + bit[i]) % MOD;
    }
    return ret;
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pw[i] = pw[i - 1] * X % MOD;
        upd(i, a[i] * pw[i] % MOD);
    }
    while (q--) {
        int o, l1, l2, r1, r2, p, v;
        cin >> o;
        if (o == 1) {
            cin >> l1 >> r1 >> l2 >> r2;
            ll v1 = (qry(r1) - qry(l1 - 1) + MOD) % MOD;
            ll v2 = (qry(r2) - qry(l2 - 1) + MOD) % MOD;
            if (v1 * pw[l2] % MOD == v2 * pw[l1] % MOD) {
                cout << 1 << ok;
            }
            else {
                cout << 0 << ok;
            }
        }
        else {
            cin >> p >> v;
            upd(p, (-a[p] + MOD + v) * pw[p] % MOD);
            a[p] = v;
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