// cpc21c1p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MN = 3e5 + 5;
int n, m, val[MN];
vector<int> adj[MN];

void dfs(int cur, int mx) {
    val[cur] = mx;
    for (int x : adj[cur]) {
        if (!val[x]) {
            dfs(x, mx);
        }
    }
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = n; i >= 1; i--) {
        if (!val[i]) {
            dfs(i, i);
        }
    }
    for (int i = n; i >= 1; i--) {
        if (val[i] > i) {
            cout << i << " " << val[i] << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
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