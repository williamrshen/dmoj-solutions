#include <iostream>
#include <string>
#include <set>

using namespace std;

#define int long long
#define ok "\n"

const int MOD = 1e9 + 7;
int n, a, b, c, d, e, f;
set<int> hm;


signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d >> e >> f;
		int hash = (a * b) * (a + b)  +  (b * c) * (b + c)  +  (c * d) * (c + d)  +  (d * e) * (d + e)  +  (e * f) * (e + f)  +  (f * a) * (a + f);
		hm.insert(hash);
	}
	if (hm.size() == n) cout << "No two snowflakes are alike." << ok;
	else cout << "Twin snowflakes found." << ok;
}