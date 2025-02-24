// daacc1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int n, m;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        stack<int> left;
        stack<int> fake;
        stack<int> right;
        for (int j = 1; j <= m; j++) {
            left.push(i * 2 * m + j);
        }
        for (int j = 1; j <= m; j++) {
            fake.push(i * 2* m + j + m);
        }
        for (int j = 1; j <= m; j++) {
            int k = fake.top();
            fake.pop();
            right.push(k);
        }
        for (int j = 0; j < 2 * m; j++) {
            int x; cin >> x;
            
            if (!left.empty() && x == left.top()) {
                left.pop();
            }
            else if (!right.empty() && x == right.top()) {
                right.pop();
            }
            else {
                cout << "no\n";
                return 0;
            }
        }
    }
    cout << "yes\n";
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