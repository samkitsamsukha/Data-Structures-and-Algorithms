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
    vector<int> a = {1, 2, 4, 5, 4, 5, 4, 5, 5, 5, 4, 7, 10, 12};
    mergeSort(a, 0, a.size()-1);
    int i = 0;
    int mode = 0;
    int runLength = 0;
    int runValue = 0;
    int modeFreq = 0;
    while(i<a.size()-1){
        runLength = 1;
        runValue = a[i];
        while(i+runLength<=a.size()-1 && a[i+runLength] == runValue){
            runLength++;
        }
        if(runLength>modeFreq){
            modeFreq = runLength;
            mode = runValue;
        }
        i = i+runLength;
    }
    cout << "Mode is " << mode << endl;
    return 0;
}