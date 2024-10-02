#include<bits/stdc++.h>
using namespace std;

int t = -1;

void push(int arr[], int x, int n){
    if(t == n-1){
        cout << "Stack overflow, Pop some elements" << endl;
        return;
    }
    t++;
    arr[t] = x;
    return;
    cout << "Added " << x << " to the stack" << endl;
}

void pop(int arr[]){
    if(t == -1){
        cout << "Stack underflow, Push some elements" << endl;
        return;
    }
    cout << "Removed " << arr[t] << " from the stack" << endl;
    t--;
    return;
}

int top(int arr[]){
    if(t == -1){
        cout << "Stack underflow, top does not exist" << endl;
        return -1;
    }
    return arr[t];
}

int main(){
    int n;
    cout << "Enter stack size: ";
    cin >> n;
    int arr[n];
    while(true){
        cout << "Operations on the stack: " << endl;
        cout << "1. Push \n2. Pop \n3. Top \n4. Exit" << endl;
        int opt;
        cin >> opt;
        switch(opt){
            case 1:{
                int x;
                cout << "Enter element: ";
                cin >> x;
                push(arr, x, n);
                break;
            }
            case 2:{
                pop(arr);
                break;
            }
            case 3:{
                cout << "Top element : " << top(arr) << endl;;
                break;
            }
            case 4:{
                cout << "Terminate stack" << endl;
                return 0;
            }
            default:{
                cout << "Invalid choice" << endl;
            }
        }
    }
    return 0;
}