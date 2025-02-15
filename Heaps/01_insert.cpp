#include <bits/stdc++.h>
using namespace std;

//  TC - O(log N) - depends on height of complete binary tree

void heapify(vector<int>& a, int n){
    int temp = a[n];
    int i = n;
    while(i>0 && temp>a[i/2]){
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;
}

int main(){
    vector<int> a = {40, 35, 15, 30, 10, 12, 6, 5, 20};
    a.push_back(50);
    heapify(a, 9);
    cout << "Heap: ";
    for(int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}