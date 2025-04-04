#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string code, newCode;
        cin >> code;
        int sum = 0, num = 0, sign = 1;
        bool inNumber = false;

        for (char ch : code) {
            if (isupper(ch)) {
                newCode += ch;
                if (inNumber) {
                    sum += sign * num;
                    num = 0;
                    sign = 1;
                }
            }
            else if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                inNumber = true;
            }
            else if (ch == '-') {
                if (inNumber) {
                    sum += sign * num;
                    num = 0;
                }
                sign = -1;
                inNumber = false;
            }
            else { // lowercase letters
                if (inNumber) {
                    sum += sign * num;
                    num = 0;
                    sign = 1;
                }
            }
        }
        sum += sign * num;

        cout << newCode << sum << endl;
    }
    return 0;
}