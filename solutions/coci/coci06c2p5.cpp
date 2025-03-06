// coci06c2p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 405;
int r, c, psa[MN][MN], out;


int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        string s; cin >> s;
        for (int j = 1; j <= c; j++) {
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + (s[j - 1] == 'X');
        }
    }
    for (int r1 = 1; r1 <= r; r1++) {
        for (int r2 = r1; r2 <= r; r2++) {
            for (int c1 = 1, c2 = 1; c2 <= c; c2++) {
                int v = psa[r2][c2] - psa[r1 - 1][c2] - psa[r2][c1 - 1] + psa[r1 - 1][c1 - 1];
                if (v > 0) {
                    c1 = c2 + 1;
                }
                else {
                    out = max(out, 2 * (r2 - r1 + 1) + 2 * (c2 - c1 + 1));
                }
            }
        }
    }
    cout << out - 1 << ok;
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