/*
    Example 1:
Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
Result: 7
    Example 2:
Input Format: arr[] = {1,2,1,3,5,6,4}
Result: 1
    Example 3:
Input Format: arr[] = {1, 2, 3, 4, 5}
Result: 4
    Example 4:
Input Format: arr[] = {5, 4, 3, 2, 1}
Result: 0
Explanation: In this example, there is only 1 peak that is at the index 0.
*/

#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int> nums){
    int n = nums.size();
    if(n==1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
            return mid;
        }
        else if(nums[mid] > nums[mid-1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return 0;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}