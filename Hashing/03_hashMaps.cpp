//Hashing using C++ STL (MAP)

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cout << "Enter number of array elements" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        //Precomputation can be done here as well
    }
    //PRECOMPUTE
    map<int, int> mpp;
    for(int i=0; i<n ; i++){
        mpp[arr[i]]++;
    }
    //FETCH
    cout << "Enter number of queries" << endl;
    int q;
    cin >> q;
    while(q--){
        int search;
        cin >> search;
        cout << search << " appears " << mpp[search] << " times." << endl;
    }
    //ITERATE THROUGH THE MAP
    for(auto it : mpp){
        cout << it.first << "-->" << it.second << endl;
    }
    /*
        for [1, 2, 3, 2, 3, 1 ,12]
        1-->2
        2-->2
        3-->2
        12-->1
        STORED IN SORTED ORDED.
    */
    return 0;
}