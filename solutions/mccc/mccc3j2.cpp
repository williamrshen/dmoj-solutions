#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

#define int long long
#define ok "\n"

const int MN = 1e4 + 5;
int n, k, speed = 0, ans = 0, speeds[15];
string t;

signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> k;
	cin >> t;
	speeds[0] = k;
	for (int i = 1; i <= n; i++) {
		if (t[i - 1] == 'F') {
			speeds[i] = speeds[i - 1];
		}
		else if (t[i - 1] == 'D') {
			speeds[i] = speeds[i - 1] + 1;
		}
		else if (t[i - 1] == 'U') {
			speeds[i] = speeds[i - 1] - 1;
			if (speeds[i] < 0) {
				speeds[i] = 0;
			}
		}
		if (speeds[i] == 0) ans++;
	}
	for (int i = 1; i <= n; i++) {
		if (speeds[i] == 0) {
			//ans++;
		}
	}
	cout << ans << ok;
	//for (int x : speeds) { cout << x; }
}