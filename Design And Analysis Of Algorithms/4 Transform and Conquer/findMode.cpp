#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while ((left <= mid) && (right <= high))
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) 
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> a = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 6, 7};
    int runLength = 0;
    int runValue = 0;
    int modeValue = 0;
    int modeFreq = 0;
    for(int i = 0; i<a.size(); i++){
        runValue = a[i];
        runLength = 0;
        while(a[i]==runValue){
            i++;
            runLength++;
        }
        if(runLength > modeFreq){
            modeFreq = runLength;
            modeValue = runValue;
        }
        i--;
    }
    cout << "Mode is " << modeValue << endl;
    return 0;
}