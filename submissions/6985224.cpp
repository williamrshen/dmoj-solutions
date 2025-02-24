#include <iostream>
#include <string>

using namespace std;
int freq[105];
int n;

int main() {
	do {
		cin >> n;
		freq[n]++;
	} while (n != -1);

	cout << "\n";
	int maxValue = 0;
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		if (freq[i] > maxValue) {
			ans = i;
			maxValue = freq[i];
		}
	}
	for (int i = 0; i <= 100; i++) {
		if (freq[i] == maxValue) {
			cout << i << "\n";
		}
	}
}