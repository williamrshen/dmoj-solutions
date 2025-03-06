// coci18c4p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 1e6 + 5;
int n, k;
long long ans = 1e18, s = 0;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int x = v[i].first;
        s += v[i].second;
        q.push(v[i].second);
        if (q.size() > k) {
            s -= q.top();
            q.pop();
        }
        if (q.size() == k) {
            ans = min(ans, x * s);
        }
    }
    cout << ans << ok;
}