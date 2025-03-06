#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"

const int MN = 10005;
int n, h[MN];
double out = 0.0;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        out += (double)(h[i] + h[i + 1]) * x / 2.0;
    }
    cout << fixed << out << ok;
}