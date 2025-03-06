// bts18p6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"
#define ll long long

const int MN = 1e5 + 5;
int n, t, l, r;
ll a, b, c;
ll d2[MN], d1[MN], d0[MN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r >> a >> b >> c;
        d2[l] += a;
        d2[r + 1] -= a;
        d1[l] += b - 2 * a * l;
        d1[r + 1] -= b - 2 * a * l;
        d0[l] += a * l * l - b * l + c;
        d0[r + 1] -= a * l * l - b * l + c;
    }
    for (int i = 1; i <= t; i++) {
        d2[i] += d2[i - 1];
        d1[i] += d1[i - 1];
        d0[i] += d0[i - 1];
        cout << d2[i] * i * i + d1[i] * i + d0[i] << ' ';
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