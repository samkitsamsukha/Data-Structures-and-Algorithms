/*
    Example 1:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
    Example 2:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: False
 */


#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            return true;
        }
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }
        else if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = search(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}