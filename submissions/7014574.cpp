#include <iostream>
#include <string>

using namespace std;

int n, cnt = 0;
string lights;

int main() {
	cin >> n;
	cin >> lights;
	for (int i = 1; i < n; i++) {
		if (lights[i] != lights[i - 1]) {
			cnt++;
		}
	}
	if (lights[n - 1] == '1') {
		cnt++;
	}
	cout << cnt << "\n";
}