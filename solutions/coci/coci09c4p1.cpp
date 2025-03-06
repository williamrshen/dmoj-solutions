#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
	cin >> A;
	for (int i = 0; i < A.size(); i++) {
		if ('A' <= A[i] && A[i] <= 'Z') {
			cout << A[i];
		}
	}
}