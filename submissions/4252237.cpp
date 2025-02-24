#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <set>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 105;
int n;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    if (n == 1) {
        cout << "1" << ok;
    }
    else if (n == 2) {
        cout << "-1" << ok;
    }
    else if (n == 3) {
        cout << "1 3 2" << ok;
    }
    else {
        cout << "1 3 2";
        for (int i = 4; i <= n; i++) {
            cout << " " << i;
        }
        cout << ok;
    }
}