#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 1000000, INF = 0x3f3f3f3f;
int n, ans = 0;

int main() {
    cin >> n;
    while (n >= 0) {
        if (n % 5 == 0) {
            ans++;
        }
        n -= 4;
    }
    cout << ans << ok;
    return 0;
}