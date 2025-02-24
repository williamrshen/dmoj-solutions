// mathp2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int MN = 1e6 + 6, MOD = 1e9 + 7;
int n, a[MN];
long long s, p = 1;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        s = (s + a[i]) % MOD;
        p = 2 * p % MOD;
    }
    cout << s * p % MOD << "\n";
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