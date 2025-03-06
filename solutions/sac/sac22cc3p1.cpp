#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ok "\n"

const int MN = 2005; // max number of nodes
int h, s, q;


int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> h >> s >> q;
    for (int i = 1; i <= q; i++) {
        cout << h - (s * i) << ok;
    }
}