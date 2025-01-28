#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int ans = 0;

void floorBST(Node* root, int x){
    if(!root) return;
    if(root->data == x){
        ans = x;
        return;
    }
    else if(root->data < x){
        ans = root->data;
        floorBST(root->right, x);
    }
    else if(root->data > x){
        floorBST(root->left, x);
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->right = new Node(14);
    
    int x;
    cout << "Enter value to Floor: ";
    cin >> x;
    floorBST(root, x);
    cout << "Floor of " << x << " is: " << ans << endl;
    return 0;
}