#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define ok "\n"

const int MN = 2005;
int n, t, ans[MN];
queue<int> tg[MN];


signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> t;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		tg[i].emplace(x);
	}
	for (int i = 0; i < t; i++) {
		vector<int> gothit[MN];
		for (int j = 1; j <= n; j++) {
			if (tg[j].empty() == true) {
				continue;
			}
			int k = tg[j].front();
			tg[j].pop();
			ans[j] = k;
			gothit[k].push_back(j);
		}
		for (int j = 1; j <= n; j++) {
			if (gothit[j].empty() == false) {
				for (int x : gothit[j]) {
					tg[j].emplace(x);
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << ans[n] << ok;
}