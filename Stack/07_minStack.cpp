#include<bits/stdc++.h>
using namespace std;   

stack<int> st;
int mini = INT_MAX;

void push(int x){
    if(st.empty()){
        st.push(x);
        mini = x;
    }
    else if(st.top() < x){
        st.push(x);
    }
    else{
        st.push(2*x - mini);
        mini = x;
    }
}

void pop(){
    if(st.empty()){
        return;
    }
    else{
        int x = st.top();
        st.pop();
        if(x < mini){
            mini = 2*mini - x;
        }
    }
}

int top(){
    if(st.empty()) return -1;
    if(st.top() > mini){
        return st.top();
    }
    else{
        return mini;
    }
}

int getMin(){
    if(st.empty()) return -1;
    return mini;
}

int main(){
    push(12);
    push(14);
    push(10);
    cout << getMin() << endl;
    pop();
    cout << getMin() << endl;
    cout << top() << endl;
    push(10);
    cout << top() << endl;
    return 0;
}