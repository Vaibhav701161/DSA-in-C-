// will write the code to hash characters in a string
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    string s;
    cin >> s;

    int hash[256] = {0}; // Initialize hash array for all ASCII characters
    for(int i = 0 ; i<s.length(); i++){
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
}