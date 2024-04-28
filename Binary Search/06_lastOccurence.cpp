/*
Last Occurrence in a sorted array
    Example 1:
Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
Output: 4
Explanation: As the target value is 13 , it appears for the first time at index number 2.
    Example 2:
Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
Output: -1
Explanation: Target value 60 is not present in the array 
*/

#include<vector>
#include<iostream>
using namespace std;

int solution(vector<int> nums, int elem, int n){
    int low = 0;
    int high = n-1;
    int pos = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == elem){
            pos = mid;
            low = mid + 1;
        }
        else if(nums[mid] < elem){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return pos;
}

int main() {
  int n = 7;
  int elem = 13;
  vector <int> nums = {3,4,13,13,13,20,40};
  // returning the last occurrence index if the element is present otherwise -1
  cout << solution(nums, elem, n) << endl;
  return 0;
}