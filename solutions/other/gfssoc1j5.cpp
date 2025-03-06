#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
#define all(__x) __x.begin(),__x.end()
#include <array>
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef unsigned __int128 u128;
typedef __int128 int128;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;


void fileio(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
//End of Template-----------------------------------------------------------------------
//Variables-----------------------------------------------------------------------------

//Functions-----------------------------------------------------------------------------
int n, m, t;
vector<int> adj[1001];
int d[1001];

int bfs (int a, int b) {
  memset(d, -1, sizeof(d));
  queue<int> q;
  q.push(a);
  d[a] = 0;
  while(!q.empty()) {
    int c = q.front(); q.pop();
    for (int x : adj[c]) {
      if (d[x] == -1) {
        d[x] = d[c] + 1;
        q.push(x);
      }
      if (d[b] != -1) return d[b];
    }
  }
  return d[b];
}

signed main() {
    cin >> n >> m >> t;
    // vector<vector<int>> ans(n + 1);
    for (int i = 0; i < m; i ++) {
      int a, b;
      cin >> a >> b;
      adj[a].pb(b);
    }
    // for (int i = 1; i <= n; i ++) {
    //   for (int j = 1; j <= n; j ++) {
    //     if (i != j) {
    //       ans[i].pb(bfs(i, j));
    //     }
    //     else ans[i].pb(0);
    //   }
    // }
    int q, ans;
    cin >> q;
    for (int i = 0; i < q; i ++) {
      int a, b;
      cin >> a >> b;
      ans = bfs(a, b);
      if (ans == -1) {
        cout << "Not enough hallways!" << endl;
      }
      else {
        cout << ans * t << endl;
      }
    }

}