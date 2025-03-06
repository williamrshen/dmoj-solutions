// macs1p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define pi pair<int, int>
#define pii pair<int, pi>

const int MN = 2e4 + 5;
int n, m, k, dis[MN][1 << 5], t[5], d;
vector<pi> adj[MN];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dis[1][0] = 0; q.push({ 0, {1, 0} });
    while (q.size()) {
        auto f = q.top(); q.pop();
        int d = f.first; pi x = f.second;
        auto ff = x;
        int u = ff.first; int mask = ff.second;
        if (d > dis[u][mask]) continue;
        if (u == n) {
            cout << d << "\n";
            return 0;
        }
        for (auto fff : adj[u]) {
            int v = fff.first; int w = fff.second;
            int nmask = mask;
            for (int K = 0; K < k; K++) {
                if (!(nmask >> K & 1) && (w >> t[K] & 1)) {
                    w -= 1 << t[K];
                    nmask |= 1 << K;
                }
            }
            if (dis[v][nmask] > d + w) {
                dis[v][nmask] = d + w;
                q.push({ dis[v][nmask], {v, nmask} });
            }
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