//The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
//The upper bound is the smallest index, ind, where arr[ind] > x.

#include<iostream>
#include<vector>
using namespace std;

/**
 * LINEAR SEARCH ALGORITHM
 * TC : O(N)
*/
int linear(vector<int> &nums, int n, int target){
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] > target){
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
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] <= target){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {3, 5, 8, 9, 15, 19};
    int n = 6;
    int target = 9;
    int ub = binary(nums, n, target);
    cout << "The upper bound for " << target << " is " << ub << endl;
}