#include <bits/stdc++.h>

using namespace std;

bool hasp = false;
int main() {
    int N;
    cin >> N;
    
    vector<char> days(N);
    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }

    int maxSunny = 0, left = 0, countP = 0;

    for (int right = 0; right < N; right++) {
        if (days[right] == 'P') {
            countP++;
            hasp = true;
        }

        while (countP > 1) { // More than one correction, move left pointer
            if (days[left] == 'P') countP--;
            left++;
        }

        maxSunny = max(maxSunny, right - left + 1);
    }
    if (!hasp) {
        cout << N -1 << "\n";
        return 0;
    }
    cout << maxSunny << endl;
    return 0;
}