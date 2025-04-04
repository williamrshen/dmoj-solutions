#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

#define ok "\n"
#define make(a, b) uniform_int_distribution<int>(a, b)(rr)
int dp[10005];

int solve(int n) {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}


int main(int argc, char** argv) {
    int n;
	cin >> n;
	cout << solve(n) << "\n";
}