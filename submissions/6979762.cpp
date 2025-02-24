#include <iostream>
using namespace std;


const int constr = 5000000;
int r[constr];
int c[constr];

int n, m, k, o;
char C;

int main(int argc, char* argv[]) {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> C >> o;
        if (C == 'R') r[o - 1]++;
        else c[o - 1]++;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (((r[i] + c[j]) % 2 != 0)) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}