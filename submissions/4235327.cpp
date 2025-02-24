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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

struct aaa {
	int num, pts, grp;
	bool operator<(aaa const& o) {
		if (o.grp == grp) {
			if (o.pts == pts) {
				return num < o.num;
			}
			else {
				return pts > o.pts;
			}
		}
		else {
			return grp < o.grp;
		}
	}
};

struct numsort {
	bool operator () (const aaa & one, const aaa & two) {
		return one.num < two.num;
	}
};

const int MN = 10005;
int n, s, k, a, b;
char r;
vector<aaa> hm;


int main() {
	scan(n); scan(s);
	for (int i = 1; i <= n / s; i++) {
		for (int j = 1; j <= s; j++) {
			int x;
			scan(x);
			hm.push_back({ x, 0, i });
		}
	}
	sort(hm.begin(), hm.end(), numsort());
	for (int i = 0; i < ((s - 1) * n) / 2; i++) {
	    scan(a); scan(b);
		r = getchar();
		if (r == 'W') {
			hm[a - 1].pts += 3;
		}
		else if (r == 'L') {
			hm[b - 1].pts += 3;
		}
		else {
			hm[a - 1].pts++;
			hm[b - 1].pts++;
		}
	}
	sort(hm.begin(), hm.end());
	scan(k);
	for (int i = k; i <= n; i += s) {
		cout << hm[i - 1].num << " ";
	}
}