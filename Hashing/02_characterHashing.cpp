//Character Hashing

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;

    //PRECOMPUTING
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }
    //FETCHING
    int q;
    cout << "Enter number of queries" << endl;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << c << " appears " << hash[c] << " times" << endl;
    }
    return 0;
}