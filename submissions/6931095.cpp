#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000005];
int q;
int x, y;
int psa[1000005];

int main() {
    
    cin >> n;

    cin >> arr[0];
    psa[0] = arr[0];


    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        psa[i] = psa[i - 1] + arr[i];
    }


    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (x == 0) {
            cout << psa[y] << endl;
        }
        else {
            cout << psa[y] - psa[x - 1] << endl;
        }
    }
}