/********************************************************************************************************************/
/*During each iteration, we will select the leftmost element from the sorted half and discard that half from further consideration. Among all the selected elements, the minimum value will serve as our answer.*/
/********************************************************************************************************************/

/*
    Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 0
    Example 2:
Input Format: arr = [3,4,5,1,2]
Result: 1
*/

int solution(vector<int> nums){
    int low = 0; 
    int high = nums.size() - 1;
    int mini = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        // If the subarray from low to high is already sorted, update mini and break the loop
        if(nums[low] <= nums[high]){
            mini = min(mini, nums[low]);
            break;
        }   
        // If the left half is sorted, update mini and move the low pointer to mid+1
        if(nums[low] <= nums[mid]){
            mini = min(nums[low], mini);
            low = mid+1;
        }
        // If the right half is sorted, update mini and move the high pointer to mid-1
        else if(nums[mid] <= nums[high]){
            mini = min(mini, nums[mid]);
            high = mid-1;
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = solution(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}