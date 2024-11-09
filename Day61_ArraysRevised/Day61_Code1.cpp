
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 1. Maximum Subarray Sum with Kadane's Algorithm
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, currentSum = 0;
    for (int num : nums) {
        currentSum += num;
        if (currentSum > maxSum) maxSum = currentSum;
        if (currentSum < 0) currentSum = 0;
    }
    return maxSum;
}

// 2. Trapping Rain Water
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left <= right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) leftMax = height[left];
            else waterTrapped += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax) rightMax = height[right];
            else waterTrapped += rightMax - height[right];
            right--;
        }
    }
    return waterTrapped;
}

// 3. Median of Two Sorted Arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    
    int n1 = nums1.size(), n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = (n1 + n2 + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == n1) ? INT_MAX : nums1[partition1];
        
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n2) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((n1 + n2) % 2 == 0)
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            else
                return max(maxLeft1, maxLeft2);
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }
    return 0.0;
}

// 4. Best Time to Buy and Sell Stock with K Transactions
int maxProfit(vector<int>& prices, int k) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int t = 1; t <= k; t++) {
        int maxDiff = -prices[0];
        for (int d = 1; d < n; d++) {
            dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff);
            maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]);
        }
    }
    return dp[k][n - 1];
}

// 5. Count Inversions in an Array
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left, swaps = 0;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else {
            arr[k++] = rightArr[j++];
            swaps += (mid + 1) - (left + i);
        }
    }
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];

    return swaps;
}

int countInversions(vector<int>& arr, int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

// Main Function
int main() {
    // Maximum Subarray Sum
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums1) << endl;

    // Trapping Rain Water
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Rain Water: " << trap(height) << endl;

    // Median of Two Sorted Arrays
    vector<int> nums2 = {1, 2}, nums3 = {3, 4};
    cout << "Median of Two Sorted Arrays: " << findMedianSortedArrays(nums2, nums3) << endl;

    // Best Time to Buy and Sell Stock with K Transactions
    vector<int> prices = {2, 4, 1};
    int k = 2;
    cout << "Max Profit with " << k << " Transactions: " << maxProfit(prices, k) << endl;

    // Count Inversions in an Array
    vector<int> arr = {8, 4, 2, 1};
    cout << "Count of Inversions: " << countInversions(arr, 0, arr.size() - 1) << endl;

    return 0;
}
