#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int top;
    int* st;

    Stack(){
        top = -1;
        st = new int[100];
    }

    void push(int x){
        top++;
        st[top] = x;
    }

    void pop(){
        if(top != -1){
            top--;
        }
        return;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    int peek(){
        if(top == -1){
            return -1;
        }
        return st[top];
    }
};

int main(){
    string s;
    cout << "Enter the PREFIX expression: ";
    cin >> s;
    Stack st;
    int l = s.length();
    for(int i = l-1; i>=0; i--){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            int x = c-'0';
            st.push(x);
        }
        else{
            int o1 = st.peek();
            st.pop();
            int o2 = st.peek();
            st.pop();
            if(c == '+') st.push(o1+o2);
            else if(c == '-') st.push(o1-o2);
            else if(c == '*') st.push(o1*o2);
            else if(c == '/') st.push(o1/o2);
        }
    }
    cout << "Answer: " << st.peek() << endl;
}