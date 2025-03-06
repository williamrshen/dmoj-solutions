// 2023S1 - Trianglane.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int n, colored, ans = 0;
vector<int> row1, row2;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> colored;
        row1.push_back(colored);
        if (colored == 1) {
            ans += 3;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> colored;
        row2.push_back(colored);
        if (colored == 1) {
            ans += 3;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (row1[i] == 1 && row1[i + 1] == 1) {
            ans -= 2;
        }
        if (row2[i] == 1 && row2[i + 1] == 1) {
            ans -= 2;
        }
    }

    for (int i = 0; i < n; i++) {
        if (row1[i] == 1 && row2[i] == 1 && i % 2 == 0) {
            ans -= 2;
        }
    }

    cout << ans << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file