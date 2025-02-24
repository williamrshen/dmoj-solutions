//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define int long long
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
#define all(__x) __x.begin(),__x.end()

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

signed main () {
  int n, m;
  cin >> n >> m;
  vi v;
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    v.pb(x);
  }
  sort(v.begin(), v.end());
  int h = n;
  for(int i = 0; i < n; i ++) {
    if (v[i] > m) {
        h = i;
        break;
    }
  }
  int ans = -1;
  for (int i = 0; i < h; i ++) {
    for (int j = i + 1; j < h; j ++) {
      if (v[i] + v[j] <= m && v[i] + v[j] > ans) {
        if (v[i] != v[j]) {
          ans = v[i] + v[j];
        }
        if (ans == m) {
          cout << ans << "\n";
          return 0;
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
  // int l = 0;
  // int r = n - 1;
  // while (l < r) {
  //   if (v[l] + v[r] <= m) {
  //     ans = v[l] + v[r];
  //     l ++;
  //   }
  //   else {
  //     r --;
  //   }
  // }
  // cout << ans << "\n";

}