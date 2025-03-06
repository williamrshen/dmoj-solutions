// dmopc21c1p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

int n, m, ans[100000];

void solve(int l, int r) {
    if (l == r) return;
    else {
        int mid = (l + r) / 2;
        solve(l, mid);
        solve(mid + 1, r);
        cout << "? " << r - mid << " " << mid - l + 1 << ok << flush;
        for (int i = mid + 1; i <= r; i++) {
            cout << i << flush;
            if (i == r) cout << ok << flush;
            else cout << " " << flush;
            cout << flush;
        }
        for (int i = l; i <= mid; i++) {
            cout << i << flush;
            if (i == mid) cout << ok << flush;
            else cout << " " << flush;
            cout << flush;
        }
        int x;
        cin >> x;
        for (int i = 0; i < x; i++) {
            int y; cin >> y;
            ans[y] = 1;
        }
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
    }
    solve(1, n);
    cout << "! " << flush;
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << flush;
    }
    cout << ok << flush;
}