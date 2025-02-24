#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    long long val[n];
    long long sum = 0;
    for(int i=0; i<n; i++){
        cin >> val[i];
        sum += val[i];
    }
    long long left = 0, right = sum;
    for(int i=0; i<n; i++){
        if(left == right){
            cout << i << endl;
            break;
        }
        else if(left > right){
            cout << "Andrew is sad." << endl;
            break;
        }
        left += val[i];
        right -= val[i];
    }
    return 0;
}