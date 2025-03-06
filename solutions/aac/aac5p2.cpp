#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <numeric>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 100005;
int n, arr[MN], g;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	cout << "? 1 2" << ok;
	cout << flush;
	cin >> arr[2];
	if (arr[2] == -1) {
		//return 0;
	}
	g = arr[2];
	for (int i = 3; i <= n; i++) {
		cout << "? 1 " << i << ok;
		cout << flush;
		cin >> arr[i];
		if (arr[i] == -1) {
			//return 0;
		}
		g = gcd(g, arr[i]);
	}
	cout << "! " << g << " ";
	cout << flush;
	for (int i = 2; i < n; i++) {
		cout << arr[i] / g << " ";
		cout << flush;
	}
	cout << arr[n] / g << ok;
	cout << flush;
	return 0;
}