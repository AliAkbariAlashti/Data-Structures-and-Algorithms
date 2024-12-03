#include <iostream>

using namespace std;

// Recursive function to calculate the position of the last remaining person in the Josephus problem
// n: number of people
// k: the step (interval) for elimination
int josephus(int n, int k) {
    // Base case: when there's only one person, they are the survivor (position 0 in 0-indexed)
    if (n == 1) {
        return 0;
    }
    
    // Recursive step: calculate the position for n-1 people, then adjust for the current size
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n = 7;  // Number of people
    int k = 1;  // Step size for elimination

    cout << josephus(n, k) + 1 << endl; // Output the position of the last remaining person
    
    return 0;
}