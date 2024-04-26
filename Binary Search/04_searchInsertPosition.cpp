/*
Input Format: arr[] = {1,2,4,7}, x = 6
Result: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.
*/

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] < target){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 4, 7};
    int target = 6;
    int ind = searchInsert(nums, target);
    cout << "The index is: " << ind << "\n";
    return 0;
}