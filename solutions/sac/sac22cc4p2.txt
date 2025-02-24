#include <iostream>

using namespace std;

typedef long long ll;

#define ok "\n"
#define MN 100005
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int k;
string s;

int f(char x, char y) {
	return min(abs(x - y), 26 - abs(x - y));
}

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> k >> s;
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = 'a'; b <= 'z'; b++) {
			for (char c = 'a'; c <= 'z'; c++) {
				for (char d = 'a'; d <= 'z'; d ++) {
					if (f(a, s[0]) + f(b, s[1]) + f(c, s[2]) + f(d, s[3]) <= k) {
						cout << a << b << c << d << ok;
					}
				}
			}
		}
	}
}