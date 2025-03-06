#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define ok "\n"
#define MN 100005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, k, dp[MN];
vector<int> a;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0) {
				if (!dp[i - a[j]]) {
					dp[i] = 1;
					break;
				}
			}
		}
	}
	cout << (dp[k] ? "First" : "Second") << ok;
}