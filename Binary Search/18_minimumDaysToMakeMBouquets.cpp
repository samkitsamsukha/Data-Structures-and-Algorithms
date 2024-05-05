// Include necessary libraries
#include<iostream>
#include<vector>
using namespace std;

// Function to check if it is possible to make m bouquets with k flowers each
// given a maximum number of days
bool possible(vector<int> nums, int day, int m, int k ){
    int count = 0; // count of flowers that can be used
    int ans = 0; // number of bouquets that can be made
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= day){ // if the flower can be used
            count++;
        }
        else{ // if the flower cannot be used
            ans = ans + (count/k); // calculate the number of bouquets that can be made
            count = 0; // reset the count
        }
    }
    ans = ans + (count/k); // calculate the number of bouquets that can be made
    if(ans>=m){ // if it is possible to make m bouquets
        return true;
    }
    return false;
}

// Brute force function to find the minimum number of days
int brute(vector<int> nums, int m, int k){
    if(nums.size() < (long long)m*k){ // if it is not possible to make m bouquets
        return -1;
    }
    int mini = INT_MAX; // minimum number of days
    int maxi = INT_MIN; // maximum number of days
    for(int i = 0; i<nums.size(); i++){
        mini = min(mini, nums[i]); // update the minimum number of days
        maxi = max(maxi, nums[i]); // update the maximum number of days
    }
    // cout << mini << " and " << maxi << endl;
    int count = 0; int ans = 0;
    for(int i = mini; i<=maxi; i++){ // iterate through all possible values
        if(possible(nums, i, m, k)){ // if it is possible to make m bouquets
            return i; // return the minimum number of days
        }
    }
    return -1; // if it is not possible to make m bouquets
}

// Optimal function to find the minimum number of days using binary search
int optimal(vector<int> nums, int m, int k){
    if(nums.size() < m*k){ // if it is not possible to make m bouquets
        return -1;
    }
    int mini = INT_MAX; // minimum number of days
    int maxi = INT_MIN; // maximum number of days
    for(int i = 0; i<nums.size(); i++){
        mini = min(mini, nums[i]); // update the minimum number of days
        maxi = max(maxi, nums[i]); // update the maximum number of days
    }
    int low = mini; // lower bound for binary search
    int high = maxi; // upper bound for binary search
    int ans = high; // initialize the answer
    while(low <= high){ // perform binary search
        int mid = low + (high-low)/2; // calculate the mid value
        if(possible(nums, mid, m, k)){ // if it is possible to make m bouquets
            ans = mid; // update the answer
            high = mid-1; // continue the binary search in the left half
        }
        else{
            low = mid+1; // continue the binary search in the right half
        }
    }
    return ans; // return the minimum number of days
}

int main(){
    vector<int> bloomDay = {7, 7, 7, 7, 13, 7, 11, 12, 7}; // input array
    int m = 2; // number of bouquets
    int k = 3; // number of flowers in each bouquet
    int ans = optimal(bloomDay, m, k); // call the optimal function
    cout << "Minimum days to make " << m << " bouquets is " << ans << endl; // print the answer
    return 0;
}