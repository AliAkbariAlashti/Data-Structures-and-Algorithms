# Binary Search

## Overview  
This folder contains two implementations of the **Binary Search** algorithm:  

1. `iterative_binary_search.cpp` - Iterative implementation.  
2. `recursive_binary_search.cpp` - Recursive implementation.  

Binary Search is an efficient algorithm used to locate a target value in a **sorted array**. It works by repeatedly dividing the search range in half until the target is found or the range becomes invalid.  

---

## How It Works  

1. **Precondition**: The input array must be sorted in ascending order.  
2. **Steps**:  
   - Calculate the middle index of the current search range.  
   - Compare the target value with the middle element:  
     - If the target equals the middle element, return its index.  
     - If the target is smaller than the middle element, search the left half.  
     - If the target is larger, search the right half.  
   - Repeat until the range is invalid (`low > high`).  

3. **Complexity**:  
   - **Time Complexity**: O(log n) in the worst case.  
   - **Space Complexity**: O(1) for iterative, O(log n) for recursive (due to call stack).  

---

## Files  

### 1. `iterative_binary_search.cpp`  
This file demonstrates an iterative implementation of Binary Search using a `while` loop.  

#### Code Example:  
```cpp
int bsearch(const vector<int>& a, int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevent overflow
        if (x < a[mid]) {
            high = mid - 1;
        } else if (x > a[mid]) {
            low = mid + 1;
        } else {
            return mid; // Element found
        }
    }
    return -1; // Element not found
}
```

#### Usage:  
```cpp
vector<int> a = {5, 9, 12, 20, 35, 50, 82, 88, 97};
int x = 12;
int result = bsearch(a, x, 0, a.size() - 1);

if (result != -1) {
    cout << "Element found at index: " << result << endl;
} else {
    cout << "Element not found" << endl;
}
```

---

### 2. `recursive_binary_search.cpp`  
This file demonstrates a recursive implementation of Binary Search using function calls.  

#### Code Example:  
```cpp
int bsearch(const vector<int>& array, int low, int high, int target) {
    if (low >= high) {
        return -1; // Base case: invalid range
    }
    int mid = low + (high - low) / 2; // Prevent overflow
    if (array[mid] == target) {
        return mid;
    }
    if (array[mid] < target) {
        return bsearch(array, mid + 1, high, target); // Search upper half
    } else {
        return bsearch(array, low, mid, target); // Search lower half
    }
}
```

#### Usage:  
```cpp
vector<int> array = {5, 9, 12, 20, 35, 50, 82, 88, 97};
int target = 12;
int result = bsearch(array, 0, array.size(), target);

if (result != -1) {
    cout << "Element found at index: " << result << endl;
} else {
    cout << "Element not found" << endl;
}
```

---

## Examples  
Given the array: `{5, 9, 12, 20, 35, 50, 82, 88, 97}` and a target value of `12`:  
- Both implementations will output:  
  ```
  Element found at index: 2
  ```  

For a target value of `100`, the output will be:  
  ```
  Element not found
  ```  

---

## When to Use Binary Search  
Binary Search is ideal for scenarios where:  
- The dataset is sorted.  
- You need fast lookups with minimal comparisons.  

Avoid using Binary Search on unsorted data without preprocessing it.