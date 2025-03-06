/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"

const int MN = 400005;
int n, m, q;
vector<int> adj[MN];
bool vis[MN];

void dfs(int x) {
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    for (int k : adj[x]) {
        dfs(k);
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i ++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    for (int i = 0; i < q; i ++) {
        char o; cin >> o;
        if (o == '+') {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            if (vis[a]) {
                dfs(b);
            }
        }
        else {
            int a; cin >> a;
            if (vis[a]) {
                cout << "YES" << ok;
            }  
            else {
                cout << "NO" << ok;
            }
        }
    }
}