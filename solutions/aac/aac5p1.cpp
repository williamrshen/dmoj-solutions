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

const int MN = 200005;
int n, arr[MN];
set<int> lol;

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		lol.insert(arr[i]);
	}
	if (2 == 3) {
		cout << n / 2 << ok;
	}
	else {
		int odd = 0;
		int evn = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] % 2 == 0) {
				evn++;
			}
			else {
				odd++;
			}
		}
		if (evn % 2 == 0 || odd % 2 == 0) {
			cout << n / 2 << ok;
		}
		else {
			cout << n / 2 - 1 << ok;
		}
	}
}