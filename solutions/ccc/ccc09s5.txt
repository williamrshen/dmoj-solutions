// ccc09s5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

#define ok "\n"

int n, m, k, d[1005][30005], out, num;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++) {
        int a, b, r, x; cin >> a >> b >> r >> x;
        for (int j = max(1, a - r); j <= min(n, a + r); j++) {
            int dd = sqrt(r * r - (a - j) * (a - j));
            d[j][max(1, b - dd)] += x;
            d[j][min(m, b + dd) + 1] -= x;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i][j - 1];
            if (d[i][j] > out) {
                out = d[i][j];
                num = 1;
            }
            else if (d[i][j] == out) {
                num++;
            }
        }
    }
    cout << out << ok << num << ok;
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