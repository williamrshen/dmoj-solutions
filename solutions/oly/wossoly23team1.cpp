// wossoly23team1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n;
long long cost;
deque<int> c;

void p() {
    for (auto x : c) {
        cout << x << " ";
    } 
    cout << "\n";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c.push_back(x);
    }
    sort(c.begin(), c.end(), greater<int>());

    while (n > 1) {
        // p();
        int front = c.front();
        int back = c.back();
        c.pop_back(); c.pop_front();
        cost += back;
        c.push_front(back + front);
        n--;
    }
    cout << cost << "\n";
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