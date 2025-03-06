#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define ok "\n"
#define MN 100005
#define pi pair<int, int>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, a, b, psa[MN];
string s;

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i - 1] == 'G') {
			psa[i] = psa[i - 1] + 1;
		}
		else {
			psa[i] = psa[i - 1];
		}
	}
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << psa[b + 1] - psa[a] << ok;
	}
}