#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>

using namespace std;

#define ok "\n"

int x, y;

int solve(int x, int y) {
    if (y > x) {
        return 2;
    }
    else {
        return solve(y, x - y) + 1;
    }
}


int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> x >> y;
    cout << solve(x, y) << ok;
}