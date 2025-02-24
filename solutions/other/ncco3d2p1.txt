#include <iostream>

using namespace std;

typedef long long ll;

#define ok "\n"

const int MN = 50005, K = 18;
int ST[K][MN], ST2[K][MN], LOG[MN];
int n, q, arr[MN];

void lll() {
    LOG[1] = 0;
    for (int i = 2; i < MN; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }
}

void www() {
    for (int i = 0; i < n; i++) {
        ST[0][i] = arr[i];
    }
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) < MN; i++) {
            ST[j][i] = min(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 0; i < n; i++) {
        ST2[0][i] = arr[i];
    }
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) < MN; i++) {
            ST2[j][i] = max(ST2[j - 1][i], ST2[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int ans(int l, int r) {
    int x = LOG[r - l + 1];
    return max(ST2[x][l], ST2[x][r - (1 << x) + 1]) - min(ST[x][l], ST[x][r - (1 << x) + 1]);
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    lll();
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    www();
    while (q--) {
        int a, b; cin >> a >> b;
        cout << ans(--a, --b) << ok;
    }
}