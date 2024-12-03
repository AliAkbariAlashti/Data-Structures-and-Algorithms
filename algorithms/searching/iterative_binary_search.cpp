#include <iostream>
#include <vector>
using namespace std;

/**
 * Performs a binary search on a sorted array to find the index of a given element.
 * 
 * @param a The sorted vector of integers.
 * @param x The element to search for.
 * @param low The starting index of the search range.
 * @param high The ending index of the search range.
 * @return The index of the element if found, otherwise -1.
 */
int bsearch(const vector<int>& a, int x, int low, int high) {
    while (low <= high) {
        // Use (low + (high - low) / 2) to prevent integer overflow
        int mid = low + (high - low) / 2; 

        if (x < a[mid]) {
            high = mid - 1; // Narrow the search to the left half
        } else if (x > a[mid]) {
            low = mid + 1; // Narrow the search to the right half
        } else {
            return mid; // Element found
        }
    }
    return -1; // Element not found
}

int main() {
    // Example sorted array
    vector<int> a = {5, 9, 12, 20, 35, 50, 82, 88, 97};

    // Element to search for
    int x = 12;

    // Perform binary search
    int result = bsearch(a, x, 0, a.size() - 1);

    // Display the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
        cout << "The number is: " << a[result] << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
