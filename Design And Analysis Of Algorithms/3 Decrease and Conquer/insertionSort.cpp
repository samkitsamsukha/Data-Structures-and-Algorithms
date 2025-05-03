#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {5, 2, 9, 1, 5, 6};
    int n = a.size();
    for(int i = 1; i<n; i++){
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    cout << "Sorted Array: ";
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}