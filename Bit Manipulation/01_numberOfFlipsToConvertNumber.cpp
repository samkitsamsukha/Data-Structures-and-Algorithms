#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter the two numbers: ";
    int a, b;
    cin >> a >> b;
    int ans = a^b;
    int count = 0;
    for(int i = 0; i < 32; i++){
        if(ans & (1 << i)){
            count++;
        }
    }
    cout << "Number of bits to be flipped to convert " << a << " to " << b << " is: " << count << endl;
}