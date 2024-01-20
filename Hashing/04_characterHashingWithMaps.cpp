//Character Hashing using the concept of Maps

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string s;
    cin >> s;
    //PRECOMPUTING
    map<char, int> mpp;
    for(int i=0; i<s.size(); i++){
        mpp[s[i]]++;
    }
    //FETCHING
    int q;
    cout << "Enter number of queries" << endl;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << c << " appears " << mpp[c] << " times" << endl;
    }
    return 0;
}