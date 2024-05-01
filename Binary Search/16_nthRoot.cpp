/*
    Example 1:
Input Format: N = 3, M = 27
Result: 3
    Example 2:
Input Format: N = 4, M = 69
Result: -1
*/

#include<iostream>
#include<vector>
using namespace std;

int func(int n ,int m, int mid){
    long long ans = 1;
    for(int i = 1; i<=n; i++){
        ans = ans * mid;
        if(ans>m){
            return 2;
        }
    }
    if(ans==m){
        return 1;
    }
    return 0;
}

int NthRoot(int n, int m){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(func(n, m, mid) == 1){
            return mid;
        }
        else if(func(n, m, mid) == 0){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n = 3, m = 125;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}