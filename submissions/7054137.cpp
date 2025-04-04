#include <iostream>

using namespace std;

int main() {
	long long left = 1, right = 2000000000;
	while (left <= right) {
		long long mid = (left + right) / 2;
		cout << mid << "\n";
		string feedback;
		cin >> feedback;
		if (feedback == "OK") {
			return 0;
		}
		else if (feedback == "SINKS") {
			left = mid + 1;
		}
		else if (feedback == "FLOATS") {
			right = mid - 1;
		}
	}
}