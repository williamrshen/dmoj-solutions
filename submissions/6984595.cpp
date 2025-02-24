#include <iostream>

using namespace std;

int n, m, ans;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int h; 
		cin >> h;
		if (h >= n) {
			ans++;
		}
	}
	cout << ans << "\n";
}