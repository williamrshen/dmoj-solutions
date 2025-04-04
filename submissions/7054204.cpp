#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> dict = {
  {"CU", "see you"},
  {":-)", "I\'m happy"},
  {":-(", "I\'m unhappy"},
  {";-)", "wink"},
  {":-P", "stick out my tongue"},
  {"(~.~)", "sleepy"},
  {"TA", "totally awesome"},
  {"CCC", "Canadian Computing Competition"},
  {"CUZ", "because"},
  {"TY", "thank-you"},
  {"YW", "you\'re welcome"},
  {"TTYL", "talk to you later"}
};


int main(int argc, char* argv[]) {
    string input = "";
    do {
        cin >> input;
        if (dict.count(input) == 0) { 
            cout << input << '\n'; 
            continue; 
        }
        cout << dict[input] << '\n';
    } while (input != "TTYL");

    return 0;
}