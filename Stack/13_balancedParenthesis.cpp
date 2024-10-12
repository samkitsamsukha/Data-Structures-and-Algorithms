#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            else{
                if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    if(st.empty()) return true;
    return false;
}

int main(){
    string s = "{([()()[{]}])}";
    if(check(s)) cout << "Balanced" << endl;
    else cout << "Not balanced" << endl;
}