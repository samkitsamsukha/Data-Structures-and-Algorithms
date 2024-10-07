#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int top;
    char* st;

    Stack(){
        top = -1;
        st = new char[100];
    }

    void push(char x){
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

    char peek(){
        if(top == -1){
            return '\0';
        }
        return st[top];
    }
};

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

int main(){
    string s;
    cout << "Enter the INFIX expression: ";
    cin >> s;
    s = '('+s+')';
    Stack st;
    string result = "";
    for(int i = 0; i<s.length(); i++){
        char c = s[i];
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9')){
            result = result+c;
        }
        else if(c == '('){
            st.push('(');
        }
        else if(c == ')'){
            while(st.peek() != '('){
                result = result+st.peek();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isEmpty() && precedence(c) <= precedence(st.peek())){
                result = result + st.peek();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }
    cout << result << endl;
}