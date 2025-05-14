#include<iostream>
#include<vector>
using namespace std;

int main(){
    string t = "I AM A STUDENT AT RV COLLEGE OF ENGINEERING";
    string p = "STUDENT";
    vector<int> shift(26, p.length());
    int x = 1;
    for(int i = 0; i<p.size()-2; i++){
        shift[p[i]-'A'] = p.size()-1-i;
    }
    int pos = 0;
    while(pos <= t.size()-p.size()){
        int j = p.size()-1; // end of pattern comparison
        while(j>=0 && p[j]==t[pos+j]){
            j--;
        }
        if(j<0){
            cout << "Matched at position " << pos << endl;
            return 0;
        }
        if(t[pos+p.size()-1] == ' '){
            pos = pos + p.size();
        }
        else{
            pos = pos + shift[t[pos+p.size()-1]-'A'];
        }
    }
    cout << "No match found" << endl;
    return 0;
}