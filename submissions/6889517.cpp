// ccc16j2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int sum, cur;
int grid[4][4];
bool ans = true;

int main()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        sum += grid[i][0];
    }

    for (int i = 0; i < 4; i++) {
        cur = 0;
        for (int j = 0; j < 4; j++) {
            cur += grid[i][j];
        }
        if (cur != sum) {
            ans = false;
        }
    }

    for (int i = 0; i < 4; i++) {
        cur = 0;
        for (int j = 0; j < 4; j++) {
            cur += grid[j][i];
        }
        if (cur != sum) {
            ans = false;
        }
    }

    
    cout << (ans ? "magic" : "not magic") << "\n";
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