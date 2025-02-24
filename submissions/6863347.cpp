// mccc4j3 - Figure Skating Fun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int n, lf = 0, rt = 0;
int scores[1000005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
        rt += scores[i];
    }
    for (int i = 1; i <= n; i++) {
        if (lf == rt) {
            cout << i - 1 << "\n";
            return 0;
        }
        else {
            lf += scores[i];
            rt -= scores[i];
        }
    }
    cout << "Andrew is sad.\n";
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