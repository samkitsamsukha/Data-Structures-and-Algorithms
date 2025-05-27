#include <iostream>
#include <cmath>
using namespace std;

int x[100]; // x[i] will store the column of queen placed in row i
int count = 0;

// Function to check if queen can be placed at row k and column i
bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false; // same column or diagonal
        }
    }
    return true;
}

// Recursive function to solve N-Queens
void nqueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                // Print solution
                count++;
                cout << "Solution " << count << ": ";
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                nqueens(k + 1, n);
            }
        }
    }
}

// Driver function
int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    nqueens(1, n);
    cout << "Total solutions: " << count << endl;
    return 0;
}
