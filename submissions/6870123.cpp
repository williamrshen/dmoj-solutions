#include <iostream>
using namespace std;
int main(){
  bool success = false;
  int n, total = 0;
  int arr[1000050];

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    total += arr[i];
  }
  int total1 = 0;
  int total2 = total;
  for(int i = n - 1 ; i >= 0; i--){
    total1 += arr[i];
    total2 -= arr[i];
    if(total2 == total1){
      cout << i << endl;
      success = true;
    }
  }
  if(!success){
    cout << "Andrew is sad." << endl;
  }
  return 0;
}