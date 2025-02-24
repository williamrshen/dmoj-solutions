#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

#define ok "\n"

const int MN = 10;
int n;
vector<int> arr;
set<int> ans;

void f(int idx, int val) {
    if (idx == n) {
        ans.insert(val);
        return;
    }
    else {
        f(idx + 1, val);
        f(idx + 1, val + arr[idx]);
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; arr.push_back(x);
    }
    f(0, 0);
    cout << ans.size() << ok;
}