//Sorting an Array using Selection Sort

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of array elements :-" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements :-" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //SELECTION SORT
    for(int i=0; i<=n-2; i++){
        int min = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    //Sorted Array
    cout << "Sorted Array :-" << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}