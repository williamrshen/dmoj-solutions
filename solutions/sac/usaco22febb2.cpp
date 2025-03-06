#include <iostream>

using namespace std;

#define ok "\n"
#define MN 100005

int n, a[MN], b[MN], m[MN], ans, x;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		while (m[a[x]]) x++;
		if (b[i] == a[x]) x++;
		else {
			ans++;
			m[b[i]] = 1;
		}
	}
	cout << ans << ok;
}