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
int n, m;
//Variables-----------------------------------------------------------------------------

//Functions-----------------------------------------------------------------------------
signed main(){
    int n, ans = 0;
    cin >> n;
    vector<int> ok;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        ok.push_back(x);
    }
    sort(ok.begin(), ok.end());
    for (int l = 0, r = n - 1; l < n / 2 - 1; l ++, r --) {
        ans += ok[r] * 2 - ok[l] * 2;
    }
    if (n % 2 == 0) {
        ans += ok[n / 2] - ok[n / 2 - 1];
    }
    else {
        int x = ok[n / 2 - 1], y = ok[n / 2], z = ok[n / 2 + 1];
        ans += max(2 * z - x - y, z + y - x * 2);
    }
    cout << ans << endl;  
}