// ccc13j2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'I' &&
            s[i] != 'O' &&
            s[i] != 'S' &&
            s[i] != 'H' &&
            s[i] != 'Z' &&
            s[i] != 'X' &&
            s[i] != 'N') {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
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