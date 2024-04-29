/*
    Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 4
    Example 2:
Input Format: arr = [3,4,5,1,2]
Result: 3
*/

/***************************** Find index of minimum element, that's it! ***********************************/

#include<iostream>
#include<vector>
using namespace std;

int solution(vector<int> nums){
    int low = 0;
    int high = nums.size()-1;
    int index = -1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low) / 2;
        if(nums[low] < nums[high]){
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            break;
        }
        else if (nums[low] <= nums[mid]){
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            low = mid + 1;
        }
        else{
            if(nums[mid] < ans){
                index = mid;
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = solution(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}