// dmopc18c2p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, m, k, a, b;
vector<int> gifts;
vector<int> adj[100005];
int ak[100005], bk[100005];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        gifts.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(a);
    ak[a] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (ak[nxt] == 0) {
                ak[nxt] = ak[cur] + 1;
                q.push(nxt);
            }
        }
    }

    q.push(b);
    bk[b] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (bk[nxt] == 0) {
                bk[nxt] = bk[cur] + 1;
                q.push(nxt);
            }
        }
    }

    //for (int i = 1; i <= n; i++) {
    //    cout << ak[i] << " " << bk[i] << "\n";
    //}
    int ans = INT_MAX;
    for (auto x : gifts) {
        ans = min(ans, ak[x] + bk[x]);
    }
    cout << ans - 2 << "\n";
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