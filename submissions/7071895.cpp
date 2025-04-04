// ccc25j5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>

using namespace std;

int r, c, m;
int row1[20005], row2[20005];
bool row;
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> r >> c >> m;
    int val = 1;
    for (int i = 1; i <= r; i++) {
        if (row) {
            for (int j = 1; j <= c; j++) {
                if (j == 1) {
                    row2[j] = min(row1[j], row1[j + 1]) + val;
                }
                else if (j == c) {
                    row2[j] = min(row1[j - 1], row1[j]) + val;
                }
                else {
                    row2[j] = min(min(row1[j - 1], row1[j + 1]), row1[j]) + val;
                }
                val++;
                if (val > m) {
                    val = 1;
                }
            }
            row = !row; 
        }
        else {
            for (int j = 1; j <= c; j++) {
                if (j == 1) {
                    row1[j] = min(row2[j], row2[j + 1]) + val;
                }
                else if (j == c) {
                    row1[j] = min(row2[j - 1], row2[j]) + val;
                }
                else {
                    row1[j] = min(min(row2[j - 1], row2[j + 1]), row2[j]) + val;
                }
                val++;
                if (val > m) {
                    val = 1;
                }
            }
            row = !row;
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= c; i++) {
        if (row) {
            ans = min(ans, row1[i]);
        }
        else {
            ans = min(ans, row2[i]);
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