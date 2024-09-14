#include <iostream>
#include <vector>
using namespace std;

// Standard Binary Search to find the index of the target element in a sorted array
int binarySeach(int arr[], int n, int target) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == target) {
            return mid; // Target found, return index
        } else if (target > arr[mid]) {
            s = mid + 1; // Search in the right half
        } else {
            e = mid - 1; // Search in the left half
        }
        mid = s + (e - s) / 2;
    }
    return -1; // Target not found
}

// Find the first occurrence of the target element in a sorted array
int findFirstOcc(int arr[], int n, int target) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (arr[mid] == target) {
            ans = mid; // Update answer and continue searching in the left half
            e = mid - 1;
        } else if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans; // Return first occurrence index
}

// Find the last occurrence of the target element in a sorted array
int findLastOcc(int arr[], int n, int target) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (arr[mid] == target) {
            ans = mid; // Update answer and continue searching in the right half
            s = mid + 1;
        } else if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans; // Return last occurrence index
}

// Find the total number of occurrences of the target element in the array
int totalOcc(int arr[], int n, int target) {
    int FirstIndex = findFirstOcc(arr, n, target);
    if (FirstIndex == -1) return 0; // Target not found
    int LastIndex = findLastOcc(arr, n, target);
    return (LastIndex - FirstIndex + 1); // Return total occurrences
}

// Find the missing element in a sequence (assuming one element is missing)
int missingEle(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
        int diff = arr[mid] - mid;
        if (diff == 1) {
            s = mid + 1;
        } else {
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    if (ans == 0) {
        return n + 1; // Special case if the missing element is the last one
    }
    return ans; // Return missing element index
}

// Find the peak element in a mountain array (array first increases and then decreases)
int peakElementInMountaionArray(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e) {
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1; // Move to the right half
        } else {
            e = mid; // Move to the left half
        }
        mid = s + (e - s) / 2;
    }
    return s; // Return the peak element index
}

// Calculate the integer square root of a number
int mySqrt(int x) {
    int s = 0;
    int e = x;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
        if (mid * mid == x) {
            return mid; // Perfect square
        } else if (mid * mid < x) {
            ans = mid;
            s = mid + 1; // Search in the right half
        } else {
            e = mid - 1; // Search in the left half
        }
        mid = s + (e - s) / 2;
    }
    return ans; // Return integer square root
}

// Search for a target element in a matrix treated as a sorted 1D array
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col;

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int currNumber = matrix[rowIndex][colIndex];
        if (currNumber == target) {
            return true; // Target found
        } else if (target > currNumber) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return false; // Target not found
}

// Find the pivot index in a rotated sorted array
int findPivotIndex(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (s == e) return s; // Pivot found
        if (mid + 1 < n && arr[mid] > arr[mid + 1]) {
            return mid; // Pivot found
        } else if (mid - 1 > 0 && arr[mid] < arr[mid - 1]) {
            return mid - 1; // Pivot found
        } else if (arr[s] > arr[mid]) {
            e = mid - 1; // Move to the left half
        } else {
            s = mid + 1; // Move to the right half
        }
        mid = s + (e - s) / 2;
    }
    return -1; // No pivot found
}

// Perform a binary search within a rotated sorted array based on the pivot
int binarySeachforPivot(int arr[], int s, int e, int target) {
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Example calls to functions
    cout << "Index of Targeted element (binary search): " << binarySeach(arr, n, 10) << endl;

    cout << "First occurrence of 5: " << findFirstOcc(arr, n, 5) << endl;
    cout << "Last occurrence of 5: " << findLastOcc(arr, n, 5) << endl;
    cout << "Total occurrences of 5: " << totalOcc(arr, n, 5) << endl;

    cout << "Missing element in sequence: " << missingEle(arr, n) << endl;

    cout << "Peak element index in mountain array: " << peakElementInMountaionArray(arr, n) << endl;

    cout << "Square root of 16: " << mySqrt(16) << endl;

    vector<vector<int>> matrix = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    cout << "Is 9 present in the matrix? " << (searchMatrix(matrix, 9) ? "Yes" : "No") << endl;

    cout << "Pivot index in rotated array: " << findPivotIndex(arr, n) << endl;

    return 0;
}
