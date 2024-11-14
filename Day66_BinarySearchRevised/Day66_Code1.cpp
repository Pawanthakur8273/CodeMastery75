#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

// 1. K-Diff Pairs in an Array
int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    int count = 0;
    for (auto& [key, val] : freq) {
        if ((k > 0 && freq.count(key + k)) || (k == 0 && val > 1))
            count++;
    }
    return count;
}

// 2. Find K-Closest Elements
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    sort(arr.begin(), arr.end(), [x](int a, int b) {
        return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
    });
    vector<int> result(arr.begin(), arr.begin() + k);
    sort(result.begin(), result.end());
    return result;
}

// 3. Exponential Search
int binarySearch(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int exponentialSearch(const vector<int>& arr, int x) {
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= x) i *= 2;
    return binarySearch(arr, i / 2, min(i, (int)arr.size() - 1), x);
}

// 4. Book Allocation Problem
bool isPossible(vector<int>& books, int students, int maxPages) {
    int studentCount = 1, pagesSum = 0;
    for (int pages : books) {
        if (pagesSum + pages > maxPages) {
            studentCount++;
            pagesSum = pages;
            if (studentCount > students) return false;
        } else {
            pagesSum += pages;
        }
    }
    return true;
}

int bookAllocation(vector<int>& books, int students) {
    int left = *max_element(books.begin(), books.end());
    int right = accumulate(books.begin(), books.end(), 0);
    int result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(books, students, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

// 5. Painter's Partition Problem
bool isFeasible(vector<int>& boards, int painters, int maxLength) {
    int total = 0, count = 1;
    for (int length : boards) {
        if (total + length > maxLength) {
            count++;
            total = length;
            if (count > painters) return false;
        } else {
            total += length;
        }
    }
    return true;
}

int paintersPartition(vector<int>& boards, int painters) {
    int left = *max_element(boards.begin(), boards.end());
    int right = accumulate(boards.begin(), boards.end(), 0);
    int result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isFeasible(boards, painters, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

// Main function to test all problems
int main() {
    // 1. K-Diff Pairs in an Array
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << "K-Diff Pairs Count: " << findPairs(nums, k) << endl;

    // 2. Find K-Closest Elements
    vector<int> arr = {1, 2, 3, 4, 5};
    int kClosest = 4, x = 3;
    vector<int> closestElements = findClosestElements(arr, kClosest, x);
    cout << "K-Closest Elements: ";
    for (int num : closestElements) cout << num << " ";
    cout << endl;

    // 3. Exponential Search
    vector<int> expArr = {1, 2, 3, 4, 10, 40, 45};
    int searchElement = 10;
    int result = exponentialSearch(expArr, searchElement);
    cout << "Exponential Search Index: " << result << endl;

    // 4. Book Allocation Problem
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << "Minimum Pages (Book Allocation): " << bookAllocation(books, students) << endl;

    // 5. Painter's Partition Problem
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    cout << "Minimum Time (Painter's Partition): " << paintersPartition(boards, painters) << endl;

    return 0;
}
