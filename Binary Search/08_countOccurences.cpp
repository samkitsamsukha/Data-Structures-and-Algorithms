/*
    Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
    Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
*/

#include<iostream>
#include<vector>
using namespace std;

int count(vector<int> nums, int elem, int n){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == elem){
            first = mid;
            high = mid-1;
        }
        else if(nums[mid] < elem){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    low = 0;
    high = n-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == elem){
            last = mid;
            low = mid + 1;
        }
        else if(nums[mid] < elem){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(first == -1){
        return 0;
    }
    return (last-first+1);
}

int main()
{
    vector<int> nums =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, elem = 0;
    int ans = count(nums, elem, n);
    cout << "The number of occurrences is: "<< ans << "\n";
    return 0;
}