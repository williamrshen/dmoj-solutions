// coci10c5p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 1e5 + 5;
int n, s, psa[MN], ans[MN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        while (l < i and psa[i - 1] - psa[l - 1] > s) {
            l++;
        }
        while (r + 1 <= n and psa[r + 1] - psa[i - 1] <= s) {
            r++;
        }
        int len = min(i - l, r - i + 1);
        ans[i - len] = max(ans[i - len], len);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = max(ans[i], ans[i - 1] - 1);
        cout << ans[i] * 2 << ok;
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