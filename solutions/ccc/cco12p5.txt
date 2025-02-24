#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

#define ok "\n"

const int MM = 100005;
int m;
bitset<102> b;
bitset<102> v;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        b[a] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        v = b;
        for (int j = 0; j <= i; j++) {
            int val = (int)((double)j * 100 / i + 0.5);
            v[val] = 0;
        }
        if (v.none()) {
            cout << i << ok;
            return 0;
        }
    }
}