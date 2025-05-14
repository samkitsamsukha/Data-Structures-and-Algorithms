#include<iostream>
using namespace std;

// Helper function to print the array
void printArray(int arr[], int n, string msg = "") {
    if (!msg.empty()) cout << msg;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void heapify(int arr[], int n, int i){
    cout << "heapify called on index " << i << " with heap size " << n << endl;
    printArray(arr, n, "Before heapify: ");
    
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        cout << "Swapping " << arr[i] << " and " << arr[largest] << endl;
        swap(arr[i], arr[largest]);
        printArray(arr, n, "After swap: ");
        heapify(arr, n, largest);
    } else {
        cout << "No swap needed\n";
    }
}

void heapSort(int arr[], int n){
    cout << "\nBuilding max heap...\n";
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
        printArray(arr, n, "Max-heap step: ");
    }

    cout << "\nExtracting elements from heap...\n";
    for(int i = n - 1; i >= 1; i--){
        cout << "Swapping root " << arr[0] << " with " << arr[i] << endl;
        swap(arr[0], arr[i]);
        printArray(arr, n, "After swap: ");
        heapify(arr, i, 0);
        printArray(arr, n, "Heap after heapify: ");
    }
}

int main(){
    int arr[] = {7, 1, 2, 4, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n, "Original array: ");
    heapSort(arr, n);
    printArray(arr, n, "\nSorted array: ");
    
    return 0;
}
