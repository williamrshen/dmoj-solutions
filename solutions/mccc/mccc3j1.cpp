#include <iostream>
#include <string>
#include <set>

using namespace std;

#define int long long
#define ok "\n"

int n, i, j;

signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> i >> j;
	if (abs(n - i * i) < abs(n - j * j)) {
		cout << 1 << ok;
	}
	else {
		cout << 2 << ok;
	}
}