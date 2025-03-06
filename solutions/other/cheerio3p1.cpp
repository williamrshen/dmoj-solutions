// cheerio3p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int MN = 1e3 + 5;

int n, m;
char g[MN][MN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'W') {
                if (g[i - 1][j] != 'W') {
                    g[i - 1][j] = 'C';
                }
                if (g[i + 1][j] != 'W') {
                    g[i + 1][j] = 'C';
                }
                if (g[i][j - 1] != 'W') {
                    g[i][j - 1] = 'C';
                }
                if (g[i][j + 1] != 'W' ){
                    g[i][j + 1] = 'C';
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << g[i][j];
        }
        cout << "\n";
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