// smac08c1p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>

using namespace std;

const int MN = 1e6 + 5;
int n, d, a[MN], dp[MN];
deque<int> q;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    q.push_back(1);
    for (int i = 2; i <= n; i++) {
        if (q.size() and q.front() < i - d) {
            q.pop_front();
        }
        dp[i] = dp[q.front()] + a[i];
        while (q.size() and dp[q.back()] >= dp[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << dp[n] << "\n";
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