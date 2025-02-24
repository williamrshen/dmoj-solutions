#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

#define ok "\n"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

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
    scan(n);
    for (int i = 0; i < n; i++) {
        int x; scan(x); arr.push_back(x);
    }
    f(0, 0);
    cout << ans.size() << ok;
}