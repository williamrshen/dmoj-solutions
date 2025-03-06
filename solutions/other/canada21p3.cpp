// canada21p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ok "\n"

int t, k; string s;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    for (cin >> t; t--; ) {
        cin >> s >> k;
        vector<char> v, m;
        for (char c : s) {
            while (v.size() and c < v.back() && k > 0) {
                m.push_back(v.back());
                v.pop_back();
                k--;
            }
            v.push_back(c);
        }
        while (v.size() and k > 0) {
            m.push_back(v.back());
            v.pop_back();
            k--;
        }
        for (char c : v) {
            cout << c;
        }
        sort(m.begin(), m.end());
        for (char c : m) {
            cout << c;
        }
        cout << ok;
    }
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