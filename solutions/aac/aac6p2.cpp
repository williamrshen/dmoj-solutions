#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define int long long
#define pi pair<int, int>


const int MN = 1005;
int n, q;
vector<pi> arr;

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    if (q == 0) {
        cout << 1 << ok;
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << " ";
        }
        cout << 1 << ok;
    }
    else {
        for (int i = 0; i < q; i++) {
            int a, b; cin >> a >> b;
            arr.push_back({ a, b });
        }
        sort(arr.begin(), arr.end(), [](pi a, pi b) {
            return a.second - a.first > b.second - b.first;
            });
        cout << arr[0].second - arr[0].first + 1 << ok;
        int val = 1;
        for (int i = 0; i < n - 1; i++) {
            cout << val++ << " ";
            if (val > arr[0].second - arr[0].first + 1) {
                val = 1;
            }
        }
        cout << val << ok;
    }
}