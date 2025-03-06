// coci12c3p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef long long ll;

ll n, m, mint = LLONG_MAX, l, r, mid;
vector<ll> tk;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        mint = min(x, mint);
        tk.push_back(x);
    }
    mint *= m;
    l = 1, r = mint, mid;
    while (l < r) {
        mid = (l + r) / 2;
        ll cando = 0;
        for (ll x : tk) {
            cando = min(m, cando + mid / x);
        }
        if (cando < m) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    cout << l << "\n";
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