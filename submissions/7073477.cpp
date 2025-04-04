#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int s = 0;

    vector<char> days(N);
    for (int i = 0; i < N; i++) {
        cin >> days[i];
        if (days[i] == 'S') {
            s++;
        }
    }
    if (s == N) {
        cout << N - 1 << "\n";
        return 0;
    }

    int maxSunny = 0, left = 0, countP = 0;

    for (int right = 0; right < N; right++) {
        if (days[right] == 'P') countP++;

        while (countP > 1) { // More than one correction, move left pointer
            if (days[left] == 'P') countP--;
            left++;
        }

        maxSunny = max(maxSunny, right - left + 1);
    }

    cout << maxSunny << endl;
    return 0;
}