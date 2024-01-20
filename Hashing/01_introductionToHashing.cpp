//Hashing an array of numbers

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter number of elements in the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements, Constraint => arr[i] <=12" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //PRECOMPUTING
    int hash[13] = {0}; //Since maximum value user can enter is 12
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    //FETCHING RESULTS
    int elem;
    cout << "Enter number for which the frequency is required" << endl;
    cin >> elem;
    cout << elem << " appears " << hash[elem] << " times" << endl;
}