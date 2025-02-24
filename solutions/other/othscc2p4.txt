// othscc2p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

int n, m, q;
map<int, pair<int, int>> a;


int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            a[x] = { i, j };
        }
    }
    for (int i = 0; i < q; i++) {
        int k, r1, c1, r2, c2;
        cin >> k >> r1 >> c1 >> r2 >> c2;
        if (a[k].first >= r1
            && a[k].first <= r2
            && a[k].second >= c1
            && a[k].second <= c2) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
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