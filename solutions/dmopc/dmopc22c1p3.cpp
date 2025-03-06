// dmopc22c1p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;

#define int long long
#define ok "\n"

const int MN = 4e5 + 5;
int n, m, q, num;
unordered_set<int> adj[MN];

void add(int u, int v) {
    if (adj[u].size() == 1) {
        int x = *adj[u].begin();
        num += adj[x].size() >= 2;
    }
    if (adj[v].size() == 1) {
        int y = *adj[v].begin();
        num += adj[y].size() >= 2;
    }
    adj[u].insert(v); adj[v].insert(u);
    num += adj[u].size() >= 2 && adj[v].size() >= 2;
}

void rem(int u, int v) {
    num -= adj[u].size() >= 2 && adj[v].size() >= 2;
    adj[u].erase(v); adj[v].erase(u);
    if (adj[u].size() == 1) {
        int x = *adj[u].begin();
        num -= adj[x].size() >= 2;
    }
    if (adj[v].size() == 1) {
        int y = *adj[v].begin();
        num -= adj[y].size() >= 2;
    }
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        add(a, b);
    }
    cout << (num > 0 ? "YES" : "NO") << ok;
    for (int i = 1; i <= q; i++) {
        int a, b; cin >> a >> b;
        if (adj[a].count(b)) {
            rem(a, b);
        }
        else {
            add(a, b);
        }
        cout << (num > 0 ? "YES" : "NO") << ok;
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