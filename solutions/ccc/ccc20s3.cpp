#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 200005, INF = 0x3f3f3f3f, MOD = 1e9 + 7, X1 = 131, X2 = 101;
string n, h;
int hash1 = 0, hash2 = 0, fn[26], fh[26];
set<int> s;

int fpow(int b, int p) {
	if (p == 0) return 1;
	int half = fpow(b, p / 2);
	if (p % 2 == 0) return half * half % MOD;
	else return half * half % MOD * b % MOD;
}

bool check() {
	for (int i = 0; i < 26; i++) {
		if (fn[i] != fh[i]) return false;
	}
	return true;
}


signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> h;
	if (n.size() > h.size()) {
		cout << 0 << ok;
		return 0;
	}
	for (int i = 0; i < n.size(); i++) {
		int c = n[i] - 'a'; fn[c] ++;
		c = h[i] - 'a'; fh[c] ++;
		hash1 *= X1; hash1 += c; hash1 %= MOD;
		hash2 *= X2; hash2 += c; hash2 %= MOD;
	}
	if (check()) s.insert(hash2 * MOD + hash1);
	for (int i = n.size(); i < h.size(); i++) {
		int c = h[i] - 'a';
		int cc = h[i - n.size()] - 'a';
		fh[c] ++; fh[cc] --;
		hash1 *= X1; hash1 %= MOD; hash1 -= cc * fpow(X1, n.size()); hash1 %= MOD; hash1 += c + MOD; hash1 %= MOD;
		hash2 *= X2; hash2 %= MOD; hash2 -= cc * fpow(X2, n.size()); hash2 %= MOD; hash2 += c + MOD; hash2 %= MOD;
		if (check()) s.insert(hash2 * MOD + hash1);
	}
	cout << s.size() << ok;
}