// acc3p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define int long long

const int MN = 1e6 + 5;
int n, k, a[MN], f[MN], d, out;

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int l = 1, r = 1; r <= n; r++) {
        cin >> a[r];
        if (++f[a[r]] == 1) {
            d++;
        }
        while (d >= k) {
            out += n - r + 1;
            if (--f[a[l]] == 0) {
                d--;
            }
            l++;
        }
    }
    cout << out << "\n";
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