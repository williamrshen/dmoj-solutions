#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

#define ok "\n"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MN = 1000005;
long long n, k;
long long ans[MN];

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    scan(n); scan(k);
    for (int i = 1; i < n; i++) {
        ans[i] = i;
    }
    ans[n] = -1 * ((n) * (n - 1) / 2) % k;
    while (ans[n] < n) {
        ans[n] += k;
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n] << ok;
}