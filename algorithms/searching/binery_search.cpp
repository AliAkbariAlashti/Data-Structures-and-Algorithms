#include <iostream>
#include <vector>
using namespace std;

int bsearch(const vector<int>& a, int x, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x < a[mid]) {
            high = mid - 1;
        } else if (x > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> a = {5, 9, 12, 20, 35, 50, 82, 88, 97};
    int x = 12;
    int result = bsearch(a, x, 0, a.size() - 1);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
        cout << "the number is : "<<a[result]<<endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
