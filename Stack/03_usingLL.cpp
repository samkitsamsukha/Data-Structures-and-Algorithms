#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    int size;
    Node(int d){
        data = d;
        next = nullptr;
    }
};
struct Stack{
    Node* top;
    int size;
    Stack(){
        top = nullptr;
        size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        cout << "Element pushed" << endl;
        size++;
    }

    int pop(){
        if(top == nullptr){
            cout << "Stack underflow" << endl;
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return val;
    }

    int peek(){
        if(top == nullptr){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        if(top == nullptr) return true;
        return false;
    }

    int stackSize(){
        return size;
    }

    void printStack(){
        Node* current = top;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    cout << "Element popped: " << s.pop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout <<"Stack empty or not? "<<s.isEmpty()<<"\n";
    cout << "stack's top element: " << s.peek() << "\n";
    return 0;
}