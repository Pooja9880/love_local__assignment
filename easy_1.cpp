#include<iostream>
#include<string>
using namespace std;

string last_word(const string &s) {
    int count = 0;
    string b;

    
    for (int i = s.length() - 1; i >= 0; --i) {
        
        if (s[i] != ' ') {
            
            b = s[i] +b;
            ++count;
        } else if (count > 0) {
          
            break;
        }
    }

    return b;
}

int main() {
    string s = "Hello World";
    string last_word_length = last_word(s);

    cout << "The last word  is " << last_word(s)<< " with length " << last_word_length.length() << endl;

    return 0;
}
