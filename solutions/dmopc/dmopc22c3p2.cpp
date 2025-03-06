// dmopc22c3p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MN = 1e6 + 5;
int n, q, a[MN], c[MN], pos[MN], x;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (c[i]) continue;
        x++;
        for (int cur = i; !c[cur]; cur = a[cur]) {
            c[cur] = x;
        }
    }
    for (int i = 1, m; i <= q; i++) {
        cin >> m;
        int out = x;
        vector<int> qry(m);
        unordered_set<int> chk, inq;
        for (int j = 0; j < m; j++) {
            cin >> qry[j];
            inq.insert(qry[j]);
            chk.insert(c[qry[j]]);
        }
        out -= chk.size();
        for (int j : qry) {
            if (!inq.count(pos[j])) {
                out++;
            }
        }
        cout << out << "\n";
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