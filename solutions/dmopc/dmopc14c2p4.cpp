#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
signed main() {
    int n, q, x, y;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i ++) {
        cin >> q;
        a[i] = a[i - 1] + q;
    }
    cin >> q;
    for (int i = 0; i < q; i ++) {
      cin >> x >> y;
      x ++; y ++;
      cout << a[y] - a[x - 1] << "\n";
    }
}