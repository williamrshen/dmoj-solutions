#define endline "\n"

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<string> vs;

#define int long long

template<class T>
T scan() {
    T v;
    cin >> v;
    return v;
}

int x, n, res[10005];
vector<int> denominations;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        denominations.push_back(k);
    }

    fill(begin(res), end(res), 9999999);
    res[0] = 0;
    for (int i = 1; i < 10005; i++) {
        for (int coin : denominations) {
            if (x - coin < 0 ) continue;

            int s = res[i-coin];

            res[i] = min(res[i], s + 1);
        }
    }

//    for (int i = 1; i <= x; i++) {
//        cout << res[i] << " ";
//    }

    cout << res[x] << endline;

}