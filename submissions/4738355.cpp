// checkereasy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 3005;
int m, n, r, c, x, r1, c1, r2, c2;
long long psa[MN][MN];

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> m >> n;
    while (1) {
        cin >> r >> c >> x;
        if (r == 0 and c == 0) {
            break;
        }
        if ((r + c) % 2 != 0) {
            psa[r][c] = x;
        }
        else {
            psa[r][c] = -x;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    while (1) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == 0 and c1 == 0) {
            break;
        }
        long long s = psa[r2][c2] - psa[r1 - 1][c2] - psa[r2][c1 - 1] + psa[r1 - 1][c1 - 1];
        cout << ((r1 + c1) % 2 != 0 ? s : -s) << ok;
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