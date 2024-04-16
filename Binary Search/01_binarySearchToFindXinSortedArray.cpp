#include<iostream>
#include<vector>
using namespace std;

/**
 * Recursive implementation of binary search.
 * TC : O(log n)
 * SC : O(log n) - recursive call stack
*/
int recursive(vector<int> nums, int low, int high, int target){
    // Base case: if the low index is greater than the high index, the target value is not in the array
    if(low>high){
        return -1;
    }
    // Calculate the middle index of the current search interval
    int mid = (low + high)/2;
    // If the middle element is equal to the target value, return the middle index
    if(nums[mid] == target){
        return mid;
    }
    // If the middle element is less than the target value, search in the right half of the interval
    else if(nums[mid] < target){
        return recursive(nums, mid+1, high, target);
    }
    // If the middle element is greater than the target value, search in the left half of the interval
    return recursive(nums, low, mid-1, target);
}

/**
 * Iterative implementation of binary search.
 * TC : O(log n)
 * SC : O(1)
*/
int iterative(vector<int> nums, int n, int target) {
    int low = 0;
    int high = n-1;
    // Continue searching until the low index is greater than the high index
    while(low <= high){
        int mid = (low + high)/2;
        // If the middle element is equal to the target value, return the middle index
        if(nums[mid] == target){
            return mid;
        }
        // If the middle element is less than the target value, search in the right half of the interval
        else if(nums[mid] < target){
            low = mid + 1;
        }
        // If the middle element is greater than the target value, search in the left half of the interval
        else{
            high = mid - 1;
        }
    }
    // If the target value is not found, return -1
    return -1;
}

int main(){
    vector<int> nums = {2, 3, 5, 6, 8, 9, 11, 13, 14, 17};
    int n = nums.size(); 
    int target = 13;
    // Find the position of the target value using both the recursive and iterative binary search algorithms
    // and print the result
    int pos = recursive(nums, 0, n-1, target);
    if(pos == -1){
        cout << "Element not found!" << endl;
    }
    else{
        cout << target << " found at " << iterative(nums, n, target)+1 << "th position" << endl;
    }
    return 0;   
}