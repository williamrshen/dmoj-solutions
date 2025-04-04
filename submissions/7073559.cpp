#include <iostream>
#include <stack>

using namespace std;
int n;
stack<int> stk;

int main() {
    cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x != 0) {
            stk.push(x);
        }
        else {
            stk.pop();
        }
    }
    int sum = 0;
    while (!stk.empty()) {
        int x = stk.top();
        stk.pop();
        sum += x;
    }
    cout << sum << endl;
}