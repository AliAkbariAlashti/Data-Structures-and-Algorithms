#include <iostream>

using namespace std;

// Function to calculate the position of the last remaining person in the Josephus problem
// n: number of people
// k: the step (interval) for elimination
int josephus(int n, int k) {
    int position = 0; // Initial position of the last remaining person (0-indexed)
    
    // Loop to calculate the position of the last remaining person based on the number of people
    for (int i = 2; i <= n; ++i) {
        position = (position + k) % i; // Update the position after each elimination
    }

    return position + 1; // Adjust to 1-indexed (since the problem usually uses 1-based indexing)
}

int main() {
    int n = 7;  // Number of people
    int k = 1;  // Step size for elimination

    cout << josephus(n, k) << endl; // Output the position of the last remaining person
    return 0;
}
