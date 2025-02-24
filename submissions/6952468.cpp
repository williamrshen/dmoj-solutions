#include <iostream>
#include <algorithm>
using namespace std;



bool arr[5000050];
int ele[2000050];

int max_element() {
    int maxele = 0;
    for (int i : ele) {
        if (i > maxele) {
            maxele = i;
        }
    }
    return maxele;
}


int main(int argc, char* argv[]) {
    int n, j;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ele[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(ele, ele + n);



    int mul = 1, ans = 0;
    int maxele = max_element();
    for (int i = 0; i < n; i++) {
        if (!arr[ele[i]]) {
            mul = 1;
            while (ele[i] * mul <= maxele) {
                arr[ele[i] * mul] = true;
                mul++;
            }
            ans++;
        }

    }
    cout << ans << '\n';
    return 0;
}