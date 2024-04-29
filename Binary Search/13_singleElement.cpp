/*
    Example 1:
Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Result: 4
    Example 2:
Input Format: arr[] = {1,1,3,5,5}
Result: 3
*/

#include<iostream>
#include<vector>
using namespace std;

int brute(vector<int> nums){
    int ans = 0;
    for(int i = 0; i<nums.size(); i++){
        if((i==0 && nums[i] != nums[i+1]) || (i==nums.size()-1 && nums[i] != nums[i-1]) || (nums[i-1]!= nums[i] && nums[i] != nums[i+1]))
        ans = nums[i];
    }
    return ans;
}

int better(vector<int> nums){
    int xorr = 0;
    for(int i = 0; i<nums.size(); i++){
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int optimal(vector<int> nums){
    if(nums.size() == 1){
        return nums[0];
    }
    else if(nums[0] != nums[1]){
        return nums[0];
    }
    else if(nums[nums.size()-1] != nums[nums.size()-2]){
        return nums[nums.size()-1];
    }
    int low = 1;
    int high = nums.size() - 2;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        // we are on left side of single element
        if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2==1) && nums[mid] == nums[mid-1]){
            low  = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = optimal(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}