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

int n, m, a1[MN], a2[MN], dp[MN], out;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	scan(n);
	for (int i = 1; i <= n; i++) {
		int x; scan(x);
		a1[x] = i;
	}
	scan(m);
	for (int i = 1; i <= m; i++) {
		int x; scan(x);
		a2[i] = a1[x];
	}
	for (int i = 1; i <= m; i++) {
		if (a2[i]) {
			if (out == 0 || a2[i] > dp[out - 1]) {
				dp[out++] = a2[i];
			}
			else {
				dp[lower_bound(dp, dp + out, a2[i]) - dp] = a2[i];
			}
		}
	}
	cout << out << ok;
}