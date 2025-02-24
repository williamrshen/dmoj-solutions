//
// Created by ryan javid on 2021-11-02.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int main() {
    cin >> n >> m;
    ll counter = 0;
    queue<ll> q;
    vector<ll> visited(10000001, 0);
    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
        ll size = q.size();
        for (ll I = 0; I < size; I++) {
            ll cur = q.front();
            q.pop();
            if (cur == m) {
                cout << counter;
                return 0;
            } else {
                if (cur * 3 < 10000001 && !visited[cur * 3]) {
                    q.push(cur * 3);
                    visited[cur * 3] = 1;
                }

                if (cur - 1 > 0 && !visited[cur - 1]) {
                    q.push(cur - 1);
                    visited[cur - 1] = 1;
                }

                if (cur - 3 > 0 && !visited[cur - 3]) {
                    q.push(cur - 3);
                    visited[cur - 3] = 1;
                }

                if (cur % 2 == 0 && !visited[cur/2]) {
                    q.push(cur/2);
                    visited[cur/2] = 1;
                }
            }
        }
        counter++;
    }
}