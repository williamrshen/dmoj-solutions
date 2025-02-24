// bf3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;


long long n;
bool p;



int main()
{
    cin >> n;
    if (n == 1 || n == 2) {
        cout << "2" << "\n";
        return 0;
    }
    if (n > 2000000000) {
        cout << "fail";
    }
    for (long long i = n; i <= 2 * n; i++) {
        p = true;
        for (long long j = 2; j < sqrt(i) + 1; j++) {
            if (i % j == 0) {
                p = false;
                break;
            }
        }
        if (p) {
            cout << i << "\n";
            return 0;
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