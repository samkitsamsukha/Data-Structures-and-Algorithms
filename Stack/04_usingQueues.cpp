#include <iostream>
#include <vector>

using namespace std;

// Function to calculate factorial modulo m
long long factorial(int n, int mod) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % mod;
    }
    return fact;
}

// Function to calculate modular inverse using Fermat's Little Theorem
long long modInverse(int a, int mod) {
    long long res = 1;
    int exponent = mod - 2;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exponent /= 2;
    }
    return res;
}

// Function to calculate the number of ways to assign performers to stages
long long calculateWays(int n, int y, int mod) {
    if (y > n) return 0;  // Can't assign more stages than performers

    // Using combination formula nCy = n! / (y! * (n-y)!)
    long long numerator = factorial(n, mod);
    long long denominator = (factorial(y, mod) * factorial(n - y, mod)) % mod;
    
    // Calculate nCy modulo mod
    return (numerator * modInverse(denominator, mod)) % mod;
}

int main() {
    int n, y;
    int mod = 1000000007;  // Modulo value for large numbers
    cout << "Enter the number of performers (n): ";
    cin >> n;
    cout << "Enter the number of stages (y): ";
    cin >> y;

    long long result = calculateWays(n, y, mod);
    cout << "Number of valid ways to assign performers to stages: " << result << endl;

    return 0;
}
