#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int s, int e, int x) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (x > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}

int firstOcc(int arr[], int s, int e, int x) {
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            ans = mid;
            e = mid - 1;
        } else if (x > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int s, int e, int x) {
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            ans = mid;
            s = mid + 1;
        } else if (x > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int TotalOcc(int arr[], int s, int e, int x) {
    int LastIndex = lastOcc(arr, s, e, x);
    int FirstIndex = firstOcc(arr, s, e, x);
    if (FirstIndex == -1 || LastIndex == -1) return 0;
    return (LastIndex - FirstIndex + 1);
}

int findMissingElement(int arr[], int n, int s, int e) {
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        int diff = arr[mid] - mid;
        if (diff == 1) {
            s = mid + 1;
        } else {
            ans = mid;
            e = mid - 1;
        }
    }
    if (s == e) {
        return n + 1;
    }
    return ans + 1;
}

int findPeakElement(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return arr[s];
}

bool Searchin2DMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col;

    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int currNumber = matrix[rowIndex][colIndex];
        if (currNumber == target) {
            return true;
        } else if (target > currNumber) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return false;
}

int mySqrt(int x) {
    int s = 0;
    int e = x;
    int ans = -1;
    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int getQuotient(int divisor, int dividend) { // Corrected typo here
    int s = 0;
    int e = dividend;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid * divisor == dividend) {
            return mid;
        }
        if (mid * divisor > dividend) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

int SearchNearlySorted(int arr[], int n, int target) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid - 1 >= 0 && arr[mid - 1] == target) {
            return mid - 1;
        }
        if (arr[mid] == target) {
            return mid;
        }
        if (mid + 1 < n && arr[mid + 1] == target) {
            return mid + 1;
        }
        if (target > arr[mid]) {
            s = mid + 2;
        } else {
            e = mid - 2;
        }
    }
    return -1;
}

int findOddOccEle(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (s == e) {
            return arr[s];  // Corrected to return the element at index 's'
        }
        if (mid & 1) {
            if (mid - 1 >= 0 && arr[mid - 1] == arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        } else {
            if (mid + 1 < n && arr[mid] == arr[mid + 1]) {
                s = mid + 2;
            } else {
                e = mid;
            }
        }
    }
    return -1;
}

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {10, 20, 50, 40, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Binary Search
    cout << "Binary Search (50): " << binarySearch(arr, 0, size - 1, 50) << endl;

    // First Occurrence
    cout << "First Occurrence of 50: " << firstOcc(arr, 0, size - 1, 50) << endl;

    // Last Occurrence
    cout << "Last Occurrence of 50: " << lastOcc(arr, 0, size - 1, 50) << endl;

    // Total Occurrences
    cout << "Total Occurrences of 50: " << TotalOcc(arr, 0, size - 1, 50) << endl;

    // Find Missing Element in Sequence (assuming the array is sorted)
    int sortedArr[] = {1, 2, 3, 5, 6};
    int sortedSize = sizeof(sortedArr) / sizeof(sortedArr[0]);
    cout << "Missing Element in sorted array: " << findMissingElement(sortedArr, sortedSize, 0, sortedSize - 1) << endl;

    // Find Peak Element
    cout << "Peak Element: " << findPeakElement(arr, size) << endl;

    // Search in 2D Matrix
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Search in 2D Matrix (5): " << (Searchin2DMatrix(matrix, 5) ? "Found" : "Not Found") << endl;

    // Square Root of a Number
    int num = 16;
    cout << "Square Root of " << num << ": " << mySqrt(num) << endl;

    // Get Quotient
    int divisor = 3, dividend = 10;
    cout << "Quotient of " << dividend << " / " << divisor << ": " << getQuotient(divisor, dividend) << endl;

    // Search in Nearly Sorted Array
    int nearlySortedArr[] = {10, 3, 40, 20, 50, 80, 70};
    int n = sizeof(nearlySortedArr) / sizeof(nearlySortedArr[0]);
    cout << "Search Nearly Sorted Array (40): " << SearchNearlySorted(nearlySortedArr, n, 40) << endl;

    // Find Odd Occurrence Element
    int oddArr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int oddSize = sizeof(oddArr) / sizeof(oddArr[0]);
    cout << "Element with Odd Occurrence: " << findOddOccEle(oddArr, oddSize) << endl;

    // Bubble Sort
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(vec);
    cout << "Sorted Array: ";
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
