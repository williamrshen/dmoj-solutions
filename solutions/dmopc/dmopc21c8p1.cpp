#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 500005;
int n, m, arr[MN], out[MN];

bool check() {
	for (int i = 1; i < n; i++) {
		if (out[i] + out[i - 1] < m) {
			return 0;
		}
	}
	return 1;
}

void p() {
	for (int i = 0; i < n; i++) {
		cout << out[i] << " ";
	}
}


int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			out[i] = arr[i / 2];
		}
		else {
			out[i] = arr[(n - 1) - (i / 2)];
		}
	}
	if (check()) {
		p();
	}
	else {
		cout << -1 << ok;
	}
}