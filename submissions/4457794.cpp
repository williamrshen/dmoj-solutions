#include <iostream>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s, t;
int hash1 = 0, hash2 = 0;
const int X = 131, MOD = 1000000007;
int ans = 0, sizers;

int pow(int b, int p) {
	if (p == 0) return 1;
	else {
		int half = pow(b, p / 2);
		half %= MOD;
		if (p % 2 == 0) return half * half % MOD;
		else return half * half % MOD * b % MOD;
	}
}

void solve() {
	cin >> s >> t;
	int val = s.size();
	sizers = min(s.size(), t.size());


	for (int i = 1; i <= sizers; i++) {

		hash1 += s[s.size() - i] * pow(X, i - 1);
		hash2 *= X;
		hash2 += t[i - 1];

		hash1 %= MOD; hash2 %= MOD;

		if (hash2 == hash1) {
			ans = i;
		}
	}

	cout << s << t.substr(ans) << "\n";
}


signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases) {


		// Normal
		solve();
		//Google
		//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}