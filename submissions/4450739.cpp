#include <iostream>
#include <deque>

using namespace std;

typedef long long ll;

#define ok "\n"
#define MN 1000005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, b, t, arr[MN];

ll f(int x) {
	deque<int> mx, mi;
	ll ret = 0;
	for (int l = 1, r = 1; r <= n; r++) {
		while (mx.size() && mx.back() < arr[r]) {
			mx.pop_back();
		}
		while (mi.size() && mi.back() > arr[r]) {
			mi.pop_back();
		}
		mx.push_back(arr[r]); mi.push_back(arr[r]);
		while (mx.size() && mi.size() && mx.front() - mi.front() > x) {
			if (mx.front() == arr[l]) {
				mx.pop_front();
			}
			if (mi.front() == arr[l]) {
				mi.pop_front();
			}
			l++;
		}
		ret += r - l + 1;
	}
	return ret;
}

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> b >> t;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << f(t) - f(b - 1) << ok;
}