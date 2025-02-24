#include <iostream>
#include <string>
using namespace std;

int low, up, di;
string pas;

int main(){
    cin >> pas;
    for(int i = 0; i < pas.length(); i++){
        if(48 <= int(pas[i]) &&  int(pas[i])<= 57){
            di++;
        }
        else if(65 <= int(pas[i]) && int(pas[i]) <= 90){
            up++;
        }
        else if( 97 <= int(pas[i]) && int(pas[i]) <= 122){
            low++;
        }
    }
    if(di > 0 && up > 1 && low > 2 && pas.length() >= 8 && pas.length() <= 12){
        cout << "Valid";
    }
    else{
        cout << "Invalid";
    }
}