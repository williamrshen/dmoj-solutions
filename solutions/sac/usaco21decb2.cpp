#include <iostream>
#include <array>

using namespace std;

#define ok "\n"

const int MN = 1000005;
int n, out = 0, p[MN], d[MN], x;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        d[i] = x - p[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        if (d[i] - d[i - 1] > 0) out += d[i] - d[i - 1];
    }
    cout << out << ok;
}