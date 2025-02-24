#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>

using namespace std;

#define ok "\n"

int m, x, y, n;
bool yt[1445], cs[1445];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    memset(yt, 0, sizeof(yt));
    memset(cs, 0, sizeof(cs));
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        for (int j = x; j <= y; j++) cs[j] = 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = x; j <= y; j++) {
            if (cs[j]) {
                cout << "Break is Over! Stop playing games! Stop watching Youtube!" << ok;
                break;
            }
            if (j == y) {
                cout << ":eyy:" << ok;
            }
        }
    }

}