#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

#define speed  cin.tie(0); cin.sync_with_stdio(0);
#define pb push_back
#define pi pair<int, int>

const int mm = 5000005;
int m, n, k, C, out = 0;
string o;
int r[mm], c[mm];

int main() {
    speed
    cin >> n >> m >> k;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < k; i++) {
        cin >> o >> C;
        if (o == "R") r[C - 1] ++;
        else c[C - 1] ++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((r[i] + c[j]) % 2 == 1) {
                out++;
            }
        }
    }
    cout << out << "\n";

    return 0;
}