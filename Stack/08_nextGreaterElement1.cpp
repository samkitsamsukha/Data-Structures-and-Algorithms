#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> a){
    stack<int> st;
    vector<int> g(a.size());
    for(int i = a.size()-1; i>=0; i--){
        if(st.empty()){
            st.push(a[i]);
            g[i] = -1;
        }
        else if(st.top() > a[i]){
            g[i] = st.top();
            st.push(a[i]);
        }
        else{
            while(!st.empty() && st.top() < a[i]){
                st.pop();
            }
            if(st.empty()){
                g[i] = -1;
                st.push(a[i]);
            }
            else{
                g[i] = st.top();
                st.push(a[i]);
            }
        }
    }
    return g;
}

int main(){
    vector<int> v = {1, 2, 3, 4};
    vector<int> g = nextGreaterElement(v);
    for(int i = 0; i < g.size(); i++){
        cout << g[i] << " ";
    }
    return 0;
}