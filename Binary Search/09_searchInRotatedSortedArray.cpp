/*
    Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
    Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
*/

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> nums, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){
            return mid;
        }
        // if left part is sorted
        else if(nums[low] <= nums[mid]) { 
            // and element is present in left half
            if(nums[low] <= target && target <= nums[mid]){
                high = mid -1; //remove right side
            }
            else{
                low = mid + 1; //remove left side
            }
        }
        // if right part is sorted
        else{
            // and element is present in right half
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(nums, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}