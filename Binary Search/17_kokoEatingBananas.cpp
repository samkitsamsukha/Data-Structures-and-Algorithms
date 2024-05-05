// Include necessary libraries
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// Function to calculate the total number of hours required to eat all the bananas
// given a mid value
int calcTH(vector<int>& nums, int mid){
    int total = 0; // initialize the total number of hours
    int n = nums.size(); // get the size of the input vector
    for(int i = 0; i<n; i++){ // iterate through the input vector
        total+=ceil((double)(nums[i])/(double)(mid)); // calculate the number of hours required to eat the current banana
    }
    return total; // return the total number of hours
}

// Function to find the minimum number of hours required to eat all the bananas
int solution(vector<int>& nums, int h){
    int low = 1; // initialize the lower bound for binary search
    sort(nums.begin(), nums.end()); // sort the input vector
    int high = nums[nums.size()-1]; // initialize the upper bound for binary search
    int ans = 1; // initialize the answer
    while(low <= high){ // perform binary search
        int mid = low + (high-low)/2; // calculate the mid value
        int TH = calcTH(nums, mid); // calculate the total number of hours required to eat all the bananas
        if(TH <= h){ // if the total number of hours is less than or equal to the given number of hours
            ans = mid; // update the answer
            high = mid-1; // continue the binary search in the left half
        }
        else{
            low = mid+1; // continue the binary search in the right half
        }
    }
    return ans; // return the minimum number of hours required to eat all the bananas
}

int main(){
    vector<int> v = {3, 6, 7, 11}; // input vector
    int h = 8; // given number of hours
    int ans = solution(v, h); // call the solution function
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n"; // print the answer
    return 0;
}