#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int top;
    int* st;

    Stack(int size){
        top = -1;
        st = new int[size];
    }

    void push(int x, int size){
        if(top == size-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        else{
            top++;
            st[top] = x;
        }
    }

    int pop(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        else{
            return st[top--];
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return st[top];
    }
};

int main(){
    cout << "Enter stack size: ";
    int n;
    cin >> n;
    Stack st(n);
    // st.pop();
    // st.push(1, n);
    // st.peek();
}