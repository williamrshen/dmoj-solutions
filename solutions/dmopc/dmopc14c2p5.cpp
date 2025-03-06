/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ok "\n"
#define MN 1000005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, m;
double dp[MN], in[MN], out[MN];
bool l[MN];
vector<int> adj[MN];


int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    memset(l, 1, sizeof(l));
    scan(n); scan(m);
    for (int i = 0; i < m; i ++) {
        int a, b; scan(a); scan(b);
        adj[b].push_back(a);
        in[b] ++;
        out[a] ++;
        l[a] = 0;
    }
    dp[1] = 1.0;
    cout << fixed << setprecision(9);
    for (int i = 1; i <= n; i++) {
        for (int x : adj[i]) {
            dp[i] += dp[x] / out[x];
        }
        if (l[i]) cout << dp[i] << ok;
    }
    return 0;
}