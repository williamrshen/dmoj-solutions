#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

#define ok "\n"
#define int long long

int n, k;

signed main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n; 
	while (n--) {
		cin >> k;
		for (int i = k + 1; ; i++) {
			if ((i * i * i) % 1000 == 888) {
				cout << i << ok;
				break;
			}
		}
	}
}