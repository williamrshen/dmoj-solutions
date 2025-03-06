// cheerio3p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int MN = 1e6 + 5;
int n, out, am1, am2; string s;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            am2++;
            if (am1 > 0) {
                out++;
                am1--;
            }
            else {
                am1++;
            }
        }
        if (s[i] == 'B') {
            am1++;
        }
        if (s[i] == 'F') {
            if (am2 > 0) {
                am2--;
            }
            else {
                if (am1 > 0) {
                    am1--;
                    out++;
                }
                else {
                    am1++;
                }
            }
        }
    }
    cout << out << "\n";
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