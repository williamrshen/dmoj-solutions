// ccc16s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int MN = 402;
int n, psa[MN], out = 0;
bool dp[MN][MN];

int sum(int x, int y) {
    return psa[y] - psa[x - 1];
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        out = max(out, x);
        psa[i] = psa[i - 1] + x;
        dp[i][i] = 1;
    }
    for (int len = 1; len < n; len++) {
        for (int l = 1, r = l + len; r <= n; r++, l++) {
            for (int p = l, q = r; p + 1 <= q; ) {
                if (dp[l][p] && dp[q][r] && (p + 1 == q || dp[p + 1][q - 1])
                    && sum(l, p) == sum(q, r)) {
                    dp[l][r] = 1;
                }
                if (sum(l, p) < sum(q, r)) p++;
                else q--;
            }
            if (dp[l][r]) {
                out = max(out, sum(l, r));
            }
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