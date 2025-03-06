// mathp3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 2e5 + 5;
int n, a[MN], p[MN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
        if (a[i - 1] > a[i] or a[i] - a[i - 1] > 1) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int l = 1;
    for (int i = 2; i <= n + 1; i++) {
        if (a[i] != a[i - 1]) {
            reverse(p + l, p + i);
            l = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
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