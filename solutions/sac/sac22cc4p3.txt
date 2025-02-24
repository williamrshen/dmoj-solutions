#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 150005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n;
vector<int> v;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	while (n--) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << v[v.size() / 2] << ok;
}