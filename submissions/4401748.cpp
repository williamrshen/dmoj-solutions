#include <iostream>
using namespace std;
int main()
{
    string word;
    getline(cin, word);

    for(int i = 0; i < word.length(); i++) {

        if(word[i] == '+' || word[i] == '-') {

            if(word[i] == '+') cout << " tighten ";
            if(word[i] == '-') cout << " loosen ";

            string numbers = "";
            for(int j = i+1; j < word.length(); j++) {
                if (!isdigit(word[j])) {
                    i += (j - i - 1);
                    break;
                }
                else cout << word[j];
            }
            
            cout << endl;
        }
        else if(!isdigit(word[i])) cout << word[i];
    }
}