#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 150005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s;
vector<int> arr;

int lis() {
	vector<int> dp;
	for (int x : arr) {
		if (dp.empty() || x > dp[dp.size() - 1]) {
			dp.push_back(x);
		}
		else {
			*lower_bound(dp.begin(), dp.end(), x) = x;
		}
	}
	return dp.size();
}

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr.push_back(s[i]);
	}
	cout << 26 - lis() << ok;
}