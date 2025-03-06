// ccc20s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 1e6 + 5;

int a[MN], b[MN], c[MN], n, ans = 1e9;
string s;

void f(int x[], int y[], int i) {
    int nx = x[n], ny = y[n];
    int notx = nx - (x[i - ny] - x[i - nx - ny]), noty = ny - (y[i] - y[i - ny]);
    ans = min(ans, notx + noty - min(y[i - ny] - y[i - nx - ny], x[i] - x[i - ny]));
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i - 1] == 'A' ? 1 : 0);
        b[i] = b[i - 1] + (s[i - 1] == 'B' ? 1 : 0);
        c[i] = c[i - 1] + (s[i - 1] == 'C' ? 1 : 0);
    }
    for (int i = 1; i <= n; i++) {
        if (i >= a[n] + b[n]) {
            f(a, b, i); f(b, a, i);
        }
        if (i >= a[n] + c[n]) {
            f(a, c, i);
            f(c, a, i);
        }
        if (i >= b[n] + c[n]) {
            f(b, c, i);
            f(c, b, i);
        }
    }
    cout << ans << ok;
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