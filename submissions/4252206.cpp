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
vector<int> arr;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 100) continue;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int out = 0;
    if (arr.size() >= 1 && arr[0] <= 100) {
        out += arr[0];
    }
    if (arr.size() >= 2 && arr[1] <= 100) {
        out += arr[1];
    }
    cout << out << ok;
}