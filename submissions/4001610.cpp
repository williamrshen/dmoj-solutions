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
int main(){
    inputJunk
    //freopen("text.txt", "r", stdin);
    cin >> n >> m;
    std::array<bool,5000005> a;
    vector<int> p;
    for (int i = 2; i <= 40004; i ++) {
        if (!a[i]) {
            p.push_back(i);
            for (int j = 2 * i; j <= 40004; j += i) {
                a[j] = true;
            }
        }
    }
    a.fill(false);
    for (int x : p) {
        for (int i = n - n % x; i <= m; i += x) {
            if (i >= n && i != x) {
                a[i - n] = true;
            }
        }
    }
    for (int i = n; i <= m; i ++) {
        if (i > 1 && !a[i - n]) {
            cout << i << endl;
        }
    }
}