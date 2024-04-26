// Input Format:
//  N = 5, arr[] = {3,5,8,15,19}, x = 9
// Result:
//  3
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

#include<iostream>
#include<vector>
using namespace std;

/**
 * LINEAR SEARCH ALGORITHM
 * TC : O(N)
*/
int linear(vector<int> &nums, int n, int target){
    for(int i = 0; i<n; i++){
        if(nums[i] >= target){
            return i;
        }
    }
    return n;
}

/**
 * BINARY SEARCH ALGORITHM
 * TC : O(logN)
*/
int binary(vector<int> &nums, int n, int target){
    int low = 0; 
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= target){
            ans = mid;
            //Eliminate right side
            high = mid-1;
        }
        else{
            //Eliminate left side
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {3, 5, 8, 15, 19};
    int n = 5;
    int target = 9;
    int lb = binary(nums, n, target);
    cout << "The lower bound for " << target << " is " << lb << endl;
}