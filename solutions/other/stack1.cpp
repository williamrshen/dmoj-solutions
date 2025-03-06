// stack1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>

using namespace std;

int t, m;
deque<string> dw;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t >> m;
    while (t--) {
        string x, c;
        cin >> x >> c;
        if (c == "in") {
            dw.push_back(x);
        }
        else {
            if (dw.back() == x) {
                dw.pop_back();
            }
            if (dw.front() == x && m >= 1) {
                m--;
                dw.pop_front();
            }
        }
    }
    for (auto x : dw) {
        cout << x << "\n";
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