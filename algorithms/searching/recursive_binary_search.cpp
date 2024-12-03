#include <iostream>
#include <vector>
using namespace std;

/**
 * Performs a binary search using recursion to find the index of a target element in a sorted array.
 * 
 * @param array The sorted vector of integers.
 * @param low The starting index of the search range.
 * @param high The ending index of the search range.
 * @param target The element to search for.
 * @return The index of the element if found, otherwise -1.
 */
int bsearch(const vector<int>& array, int low, int high, int target) {
    // Base case: If the range is invalid, the target is not found
    if (low >= high) {
        return -1;
    }

    // Use a safe method to calculate the middle index
    int mid = low + (high - low) / 2;

    // Check if the middle element is the target
    if (array[mid] == target) {
        return mid;
    }

    // Recursively search in the appropriate half
    if (array[mid] < target) {
        return bsearch(array, mid + 1, high, target); // Search the upper half
    } else {
        return bsearch(array, low, mid - 1, target); // Search the lower half
    }
}

int main() {
    // Example sorted array
    vector<int> array = {5, 9, 12, 20, 35, 50, 82, 88, 97};

    // Element to search for
    int target = 12;

    // Perform recursive binary search
    int result = bsearch(array, 0, array.size(), target);

    // Display the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
        cout << "The number is: " << array[result] << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
