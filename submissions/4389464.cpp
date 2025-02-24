#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"
#define int long long

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

vector<int> out;

void solve(int x) {
	out.push_back(x);
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			out.push_back(i);
			if (i * i != x) {
				out.push_back(x / i);
			}
		}
	}
	//sort(out.begin(), out.end());
	cout << out[0];
	for (int i = 1; i < out.size(); i++) {
		cout << " " << out[i];
	}
	cout << ok;
}

const int MN = 100005, MOD = 1000000007;
int n, ans;
vector<int> a;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	int x; cin >> x;
	a.push_back(x);
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (i == 1) ans = abs(x - a[i - 1]);
		else ans = gcd(ans, abs(x - a[i - 1]));
		a.push_back(x);
	}
	solve(ans);
}