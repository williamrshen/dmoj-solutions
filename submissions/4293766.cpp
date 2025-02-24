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

int x, n, res[10001];
vector<int> denominations;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        denominations.push_back(scan<int>());
    }

    fill(res, res + x + 1, INT_MAX);

    for (int i = 1; i <= x; i++) {
        for (int coin : denominations) {
            if (coin > x) continue;

            int s = res[i-coin];

            if (s != INT_MAX && s + 1 < res[i]) res[i] = s + 1;
        }
    }

//    for (int i = 1; i <= x; i++) {
//        cout << res[i] << " ";
//    }

    cout << res[x] << endline;

}