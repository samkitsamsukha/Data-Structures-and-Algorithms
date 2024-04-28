/*
    Floor Ceil in Sorted Array 

    Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

    Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> solution(vector<int> nums, int n, int target){
    int low = 0; 
    int high = n-1;
    int f = -1, c = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] <= target){
            f = nums[mid];
            low = mid+1;
        }
        if(nums[mid] >= target){
            c = nums[mid];
            high = mid-1;
        }
    }
    return {f, c};
}

int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int target = 2;
    vector<int> ans = solution(nums, 6, target);
    cout << "The floor is: " << ans[0] << endl;
    cout << "The ceil is: " << ans[1] << endl;
    return 0;
}