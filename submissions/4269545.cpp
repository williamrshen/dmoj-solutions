#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define pii pair<pi, int>

const int MN = 200005, INF = 0x3f3f3f3f;
int n, arr[MN];

int main() {
    cin >> n;
    int odd = 0, eve = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            eve++;
        }
        else odd++;
    }
    cout << floor(eve / 2) + floor(odd / 2) << ok;
}