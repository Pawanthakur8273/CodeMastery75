#include <iostream>
#include <limits.h>
using namespace std;

// Print the array
void printArray(int arr[], int n, int index) {
    if (index >= n) {
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, n, index + 1);
}

// Search in the array
void SearchInArray(int arr[], int size, int index, int target, int& ans) {
    if (index >= size) {
        ans = -1;
        return;
    }
    if (arr[index] == target) {
        ans = index;
        return;
    }
    SearchInArray(arr, size, index + 1, target, ans);
}

// Check if the array is sorted
void CheackSorted(int arr[], int size, int index, bool& ans) {
    if (index >= size) {
        ans = true;
        return;
    }
    if (arr[index - 1] > arr[index]) {
        ans = false;
        return;
    }
    CheackSorted(arr, size, index + 1, ans);
}

// Get the maximum element from the array
void getMax(int arr[], int size, int index, int& maxi) {
    if (index >= size) {
        return;
    }
    if (maxi < arr[index]) {
        maxi = arr[index];
    }
    getMax(arr, size, index + 1, maxi);
}

// Get the minimum element from the array
void getMin(int arr[], int size, int index, int& mini) {
    if (index >= size) {
        return;
    }
    if (mini > arr[index]) {
        mini = arr[index];
    }
    getMin(arr, size, index + 1, mini);
}

// Print all odd-indexed elements
void printAllOdds(int arr[], int size, int index) {
    if (index >= size) {
        return;
    }
    cout << arr[index] << " ";
    printAllOdds(arr, size, index + 2);
}

// Print all even-indexed elements
void PrintAllEvens(int arr[], int size, int index) {
    if (index >= size) {
        return;
    }
    cout << arr[index] << " ";
    PrintAllEvens(arr, size, index + 2);
}

// Print the digits of a number
void printDigits(int n) {
    if (n > 0) {
        int digit = n % 10;
        cout << digit << " ";
        n = n / 10;
    } else {
        return;
    }
    printDigits(n);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target number to search in array: ";
    cin >> target;

    int n;
    cout << "Enter a number to print its digits: ";
    cin >> n;

    cout << "Printing Array: " << endl;
    printArray(arr, size, 0);
    cout << endl << endl;

    int ans = -1;
    SearchInArray(arr, size, 0, target, ans);
    if (ans >= 0) {
        cout << "Target found at index: " << ans << endl;
    } else {
        cout << "Target Not Found! Sorry!" << endl;
    }

    cout << endl;
    bool ans1 = true;
    CheackSorted(arr, size, 1, ans1);
    if (ans1) {
        cout << "The Array is Sorted" << endl;
    } else {
        cout << "Oops! The Array is Not Sorted" << endl;
    }

    int maxi = INT_MIN;
    getMax(arr, size, 0, maxi);
    cout << "Max Element of the array is: " << maxi << endl;

    int mini = INT_MAX;
    getMin(arr, size, 0, mini);
    cout << "Minimum Element of the Array is: " << mini << endl;

    cout << "Printing all Odds: " << endl;
    printAllOdds(arr, size, 1);
    cout << endl << "Printing all Evens: " << endl;
    PrintAllEvens(arr, size, 0);

    cout << endl << "Printing Digits of a Number: " << endl;
    printDigits(n);

    return 0;
}
