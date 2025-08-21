#include <bits/stdc++.h>
using namespace std;

int memoize(int i, int prev, vector<int>& a, vector<vector<int>>& dp){
    if(i == a.size()) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    int nt = 0 + memoize(i+1, prev, a, dp);
    int t = 0;
    if(prev == -1 || a[i] > a[prev]){
        t = 1 + memoize(i+1, i, a, dp);
    }
    return dp[i][prev+1] = max(t, nt);
}

int main(){
    vector<int> a = {10, 9, 2, 3, 5, 4, 101, 18};
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << "Length of longest increasing subsequence using memoization: " << memoize(0, -1, a, dp) << endl;
    return 0;
}