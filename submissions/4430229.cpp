#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#define ok "\n"
#define MN 1000005
#define pi pair<int, int>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n;
vector<int> dp;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	scan(n);
	for (int i = 1; i <= n; i++) {
		int x; scan(x);
		if (dp.empty() || x > dp[dp.size() - 1]) {
			dp.push_back(x);
		}
		else {
			*lower_bound(dp.begin(), dp.end(), x) = x;
		}
	}
	cout << dp.size() << ok;
}