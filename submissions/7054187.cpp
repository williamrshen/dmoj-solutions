#include <iostream>
#include <set>

using namespace std;
int n;
set<int> s;
int main() {
	cin >> n;
	for (int i = 0;i < n; i++) {
		int a; cin >> a;
		s.insert(a);
	}
	cout << s.size() << "\n";
}