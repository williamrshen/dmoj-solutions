// ccc14s3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int t, n;
stack<int> mt, bc;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mt.push(x);
        }
        int need = 1;
        while (!mt.empty()) {
            int nxt = mt.top();
            mt.pop();
            bc.push(nxt);
            while (!bc.empty() && bc.top() == need) {
                bc.pop();
                need++;
            }
        }
        cout << (need == n + 1 ? "Y" : "N") << "\n";
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