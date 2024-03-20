/**
 * Element occuring more than n/3 times in an array
*/

// Brute - same as n/2 times, just make array to add elements and finish if 2 elements added
// Better (Hashing) - same as n/2 times, just make array to add elements and finish if 2 elements added

#include<iostream>
#include<vector>
using namespace std;

/**
 * Moore's Voting Algorithm - Modified Version
*/
vector<int> optimal(vector<int> nums){
    int c1 = 0; 
    int c2 = 0;
    int e1, e2;
    for(int i = 0 ; i<nums.size(); i++){
        if(c1 == 0 && nums[i] != e2){
            c1 = 1;
            e1 = nums[i];
        }
        else if(c2 == 0 && nums[i] != e1){
            c2 = 1;
            e2 = nums[i];
        }
        else if(nums[i] == e1){
            c1++;
        }
        else if(nums[i] == e2){
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    return {e1, e2};
}
int main(){
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> ans = optimal(nums);
    cout << ans[0] << ", " << ans[1];
    return 0;
}