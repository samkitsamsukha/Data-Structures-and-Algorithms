#include<map>
#include<vector>
#include<iostream>
using namespace std;

/*
    Brute Force Solution
    TC : O(N^2)
    SC : O(1)
*/
int brute(vector<int> &arr, long long k){
    int len = 0;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum = sum + arr[j];
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

/*
    Better Approach using HASHMAP
    TC : O(N^2) - Worst Case
    SC : O(N)
*/
int better(vector<int> &arr, long long k){
    int maxLen = 0;
    long long sum = 0;
    map<long long, int> preSum;
    for(int i=0; i<arr.size(); i++){
        sum = sum + arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSum.find(rem) != preSum.end()){
            int len = i-preSum[rem];
            maxLen = max(maxLen, len);
        }
        if(preSum.find(sum) == preSum.end()){
            preSum[sum] = i;
        }
    }
    return maxLen;
}

/*
    Optimal Solution using 2 pointer approach and greedy algorithm
    TC : O(2N)
    SC : O(1)
*/
int optimal(vector<int> arr, long long k){
    int maxLen = 0;
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int n = arr.size();
    while(right < n){
        while(sum > k && left <= right){
            sum = sum - arr[left];
            left--;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        sum = sum + arr[right];
    }
    return maxLen;
}

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 1, 3, 4, 2, 3};
    long long k = 6;
    // int ans = brute(arr, k);
    int ans = better(arr, k);
    // int ans = brute(arr, k);
    cout << ans << endl;
    return 0;
}