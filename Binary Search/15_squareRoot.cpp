/*
    Example 1:
Input Format: n = 36
Result: 6
    Example 2:
Input Format: n = 28
Result: 5
*/

#include<iostream>
#include<cmath>
using namespace std;

int brute(int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        int val = i*i;
        if(val <= n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

int better(int n){
    return sqrt(n);
}

int optimal(int n){
    int low = 1;
    int high = n;
    int ans = 0;
    while(low <= high){
        long long mid = low + (high-low)/2;
        long long val = mid * mid;
        if(val <= n){
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 63;
    int ans = optimal(n);
    cout << "The floor of square root of " << n << " is: " << ans << endl;
    return 0;
}