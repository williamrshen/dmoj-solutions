// coci16c2p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define ok "\n"

const int MN = 505;
int n, m, k, x;
string s, a[MN], out = "";

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m >> k >> x >> s;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		sort(a[i].begin(), a[i].end());
	}
	ll cnt = 1;
	int pos = 0;
	for (int i = m - 1; i >= 0; i--) {
		cnt *= k;
		if (cnt >= x) {
			pos = i;
			break;
		}
	}
	x--;
	cnt /= k;
	for (int i = 0; i < m; i++) {
		if (i < pos) {
			out.push_back(a[i][0]);
		}
		else {
			out.push_back(a[i][(int)(x / cnt)]);
			x %= cnt;
			cnt /= k;
		}
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') {
			cout << out[idx];
			idx++;
		}
		else {
			cout << s[i];
		}
	}
	cout << ok;
}