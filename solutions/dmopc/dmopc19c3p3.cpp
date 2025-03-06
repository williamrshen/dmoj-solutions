#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 150005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, psa[MN], bit[2 * MN];
long long ans = 0;

void upd(int pos, int val) {
	pos += n + 1;
	for (int i = pos; i < 2 * MN; i += (i & -i)) {
		bit[i] += val;
	}
}

int qry(int pos) {
	pos += n + 1;
	int ret = 0;
	for (int i = pos; i > 0; i -= (i & -i)) {
		ret += bit[i];
	}
	return ret;
}

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		psa[i] = psa[i - 1] + ((x == 1) * 2 - 1);
	}
	upd(0, 1);
	for (int i = 1; i <= n; i++) {
		ans += qry(psa[i] - 1);
		upd(psa[i], 1);
	}
	cout << ans << ok;
}