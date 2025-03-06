// dmopc21c9p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int t;
string a, b;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        stack<char> stk;
        cin >> a >> b;
        b = b + ".";
        int idx = 0;
        for (char x : a) {
            stk.push(x);
            if (stk.size() == 1 && stk.top() == b[idx]) {
                stk.pop();
                idx++;
                continue;
            }
                
            while (stk.size() >= 2 && stk.top() != 'z') {
                char top1 = stk.top();
                stk.pop();
                char top2 = stk.top();
                if (top1 != top2) {
                    stk.push(top1);
                    break;
                }
                stk.pop();
                stk.push((char)((int)(top2) + 1));
                if (stk.size() == 1 && stk.top() == b[idx]) {
                    stk.pop();
                    idx++;
                    break;
                }
            }

        }
        if (idx == b.size() - 1 && stk.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
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