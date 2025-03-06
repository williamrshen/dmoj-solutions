#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
#define ok "\n"
#define MN 45
#define pi pair<int, int>
#define pl pair<ll, ll>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, x, y;
ll ans[MN];
pi c[MN];
ll tmp[10000];
vector<pair<pl, int>> le, rt;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> c[i].first >> c[i].second;
	}
	int h = n / 2, r = n - h;

	for (int msk = 0; msk < (1 << h); msk++) {
		ll cx = 0, cy = 0;
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			if (msk >> i & 1) {
				cx += c[i].first;
				cy += c[i].second;
				cnt++;
			}
		}
		le.push_back({ {cx, cy}, cnt });
	}
	
	for (int msk = 0; msk < (1 << r); msk++) {
		ll cx = 0, cy = 0;
		int cnt = 0;
		for (int i = 0; i < r; i++) {
			if (msk >> i & 1) {
				cx += c[h + i].first;
				cy += c[h + i].second;
				cnt++;
			}
		}
		rt.push_back({ {x - cx, y - cy}, cnt });
	}

	sort(le.begin(), le.end());
	sort(rt.begin(), rt.end());
	for (int i = 0, j = 0; i < le.size(); i++) {
		if (i == 0 || le[i - 1].first != le[i].first) {
			memset(tmp, 0, sizeof(tmp));
			while (j < rt.size() && rt[j].first < le[i].first) {
				j++;
			}
			while (j < rt.size() && rt[j].first == le[i].first) {
				tmp[rt[j].second] ++;
				j++;
			}
		}
		for (int k = 0; k <= r; k++) {
			ans[le[i].second + k] += tmp[k];
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ok;
	}
}