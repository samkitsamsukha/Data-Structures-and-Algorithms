/*
    Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
Result: 3
    Example 2:
Input Format: N = 4, arr[] = {8,4,2,3}, limit = 10
Result: 2
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int calculate(vector<int> nums, int mid){
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum+ = ceil((double)(nums[i])/(double)(mid));
    }
    return sum;
}

int smallestDivisor(vector<int> nums, int limit){
    if(nums.size() > limit){
        return -1;
    }
    int low = 1; 
    int high = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(calculate(nums, mid) <= limit){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}