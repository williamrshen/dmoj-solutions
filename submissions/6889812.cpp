#include <iostream>

int arr[150];
int input;
int main (int argc, char *argv[]) {
  while(input != -1){
    std::cin >> input;
    arr[input]++;
  }
  int maxIndex = 0;
  int max = 0;
  for(int i = 0; i < 100; i++){
    if(arr[i] > max){
      max = arr[i];
      maxIndex = i;
    }
  }
  for(int i = 100; i >= 0; i--){
    if(arr[i] == max){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}