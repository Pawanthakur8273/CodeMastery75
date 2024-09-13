// 1. Find Pivot Index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int leftKaSum = 0;
            int rightKaSum = 0;
            int leftKaIndex;
            int rightKaIndex;

            for (leftKaIndex = 0; leftKaIndex < i; leftKaIndex++) {
                leftKaSum += nums[leftKaIndex];
            }
            for (rightKaIndex = i + 1; rightKaIndex < n; rightKaIndex++) {
                rightKaSum += nums[rightKaIndex];
            }
            if (rightKaSum == leftKaSum) {
                return i;
            }
        }
        return -1;
    }
};

// 2. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int m = 0;

        while (m <= j) {
            if (nums[m] == 0) {
                swap(nums[i], nums[m]);
                i++;
                m++;
            }
            else if (nums[m] == 1) {
                m++;
            }
            else {
                swap(nums[m], nums[j]);
                j--;
            }
        }
    }
};

// 3. Find Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int totalSum = (n * (n + 1)) / 2;
        return totalSum - sum;
    }
};

// 4. Segregate Positive and Negative Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregateElements(vector<int>& arr) {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) {
                neg.push_back(arr[i]);
            }
            else {
                pos.push_back(arr[i]);
            }
        }

        int k;
        for (k = 0; k < pos.size(); k++) {
            arr[k] = pos[k];
        }
        for (int j = k, i = 0; j < arr.size() && i < neg.size(); j++, i++) {
            arr[j] = neg[i];
        }
    }
};

// 5. Find Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> vec(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            vec[nums[i]]++;
        }
        int maxi = INT_MIN;
        int ans = -1;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] > maxi) {
                maxi = vec[i];
                ans = i;
            }
        }
        return ans;
    }
};

// 6. Find Common Elements in Three Arrays
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0, j = 0, k = 0;
        set<int> st;
        vector<int> ans;

        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                st.insert(arr1[i]);
                i++; j++; k++;
            }
            else if (arr1[i] < arr2[j]) {
                i++;
            }
            else if (arr2[j] < arr3[k]) {
                j++;
            }
            else {
                k++;
            }
        }

        for (auto i : st) {
            ans.push_back(i);
        }
        return ans;
    }
};

// 7. Convert Array to Wave-Like Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void convertToWave(int n, vector<int>& arr) {
        for (int i = 1; i < arr.size(); i += 2) {
            swap(arr[i - 1], arr[i]);
        }
    }
};

// Main function to test all programs
int main() {
    // Test for Find Pivot Index
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    Solution sol1;
    cout << "Pivot Index: " << sol1.pivotIndex(nums1) << endl;

    // Test for Sort Colors
    vector<int> nums2 = {2, 0, 2, 1, 1, 0};
    Solution sol2;
    sol2.sortColors(nums2);
    cout << "Sorted Colors: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    // Test for Find Missing Number
    vector<int> nums3 = {3, 0, 1};
    Solution sol3;
    cout << "Missing Number: " << sol3.missingNumber(nums3) << endl;

    // Test for Segregate Positive and Negative Numbers
    vector<int> nums4 = {1, -1, 3, -2, -3, 5};
    Solution sol4;
    sol4.segregateElements(nums4);
    cout << "Segregated Positive and Negative: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;

    // Test for Find Duplicate Number
    vector<int> nums5 = {1, 3, 4, 2, 2};
    Solution sol5;
    cout << "Duplicate Number: " << sol5.findDuplicate(nums5) << endl;

    // Test for Find Common Elements in Three Arrays
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
    Solution sol6;
    vector<int> common = sol6.commonElements(arr1, arr2, arr3);
    cout << "Common Elements: ";
    for (int num : common) cout << num << " ";
    cout << endl;

    // Test for Convert Array to Wave-Like Array
    vector<int> nums7 = {10, 90, 49, 2, 1, 5, 23};
    Solution sol7;
    sol7.convertToWave(nums7.size(), nums7);
    cout << "Wave Array: ";
    for (int num : nums7) cout << num << " ";
    cout << endl;

    return 0;
}
