#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Count Inversions
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid, inversions = 0;

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            inversions += (mid - i); // Elements remaining in left half
        }
    }
    while (i < mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; ++k) arr[k] = temp[k - left];

    return inversions;
}

int countInversions(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int inversions = countInversions(arr, left, mid) + countInversions(arr, mid + 1, right);
    inversions += mergeAndCount(arr, left, mid + 1, right);

    return inversions;
}

// 2. In-Place Merge Sort
void mergeInPlace(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            ++i;
        } else {
            int value = arr[j];
            for (int k = j; k > i; --k) arr[k] = arr[k - 1];
            arr[i] = value;

            ++i; ++j; ++mid;
        }
    }
}

void mergeSortInPlace(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortInPlace(arr, left, mid);
    mergeSortInPlace(arr, mid + 1, right);

    mergeInPlace(arr, left, mid, right);
}

// 3. Maximum Subarray
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// 4. Combination Sum
void combinationSumHelper(vector<int>& candidates, int target, vector<int>& current, int index, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (target < 0) return;

    for (int i = index; i < candidates.size(); ++i) {
        current.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], current, i, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    combinationSumHelper(candidates, target, current, 0, result);
    return result;
}

// 5. Combination Sum II
void combinationSum2Helper(vector<int>& candidates, int target, vector<int>& current, int index, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (target < 0) return;

    for (int i = index; i < candidates.size(); ++i) {
        if (i > index && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
        current.push_back(candidates[i]);
        combinationSum2Helper(candidates, target - candidates[i], current, i + 1, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    combinationSum2Helper(candidates, target, current, 0, result);
    return result;
}

// Main function for testing
int main() {
    // Example input for Count Inversions
    vector<int> arr1 = {8, 4, 2, 1};
    cout << "Count of Inversions: " << countInversions(arr1, 0, arr1.size() - 1) << endl;

    // Example input for In-Place Merge Sort
    vector<int> arr2 = {5, 2, 4, 7, 6, 1, 3};
    mergeSortInPlace(arr2, 0, arr2.size() - 1);
    cout << "In-Place Merge Sorted Array: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    // Example input for Maximum Subarray
    vector<int> arr3 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(arr3) << endl;

    // Example input for Combination Sum
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = combinationSum(candidates1, target1);
    cout << "Combination Sum: ";
    for (const auto& vec : result1) {
        cout << "[ ";
        for (int x : vec) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    // Example input for Combination Sum II
    vector<int> candidates2 = {10, 1, 2, 7, 6, 1, 5};
    int target2 = 8;
    vector<vector<int>> result2 = combinationSum2(candidates2, target2);
    cout << "Combination Sum II: ";
    for (const auto& vec : result2) {
        cout << "[ ";
        for (int x : vec) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    return 0;
}
