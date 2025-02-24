#include <iostream>
#include <stack>

using namespace std;

int k;
stack<int> s;

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n; cin >> n;
		if (n != 0) {
			s.push(n);
		}
		else {
			s.pop();
		}
	}
	int out = 0;
	while (!s.empty()) {
		out += s.top();
		s.pop();
	}
	cout << out << "\n";
}