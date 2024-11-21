#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Combination Sum - II
void findCombinations(int ind, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = ind; i < candidates.size(); i++) {
        if (i > ind && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        current.push_back(candidates[i]);
        findCombinations(i + 1, target - candidates[i], candidates, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(0, target, candidates, current, result);
    return result;
}

// Permutation - II
void permuteUniqueHelper(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;
        used[i] = true;
        current.push_back(nums[i]);
        permuteUniqueHelper(nums, current, used, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    permuteUniqueHelper(nums, current, used, result);
    return result;
}

// Beautiful Arrangement
int countArrangementHelper(int n, int pos, vector<bool>& visited) {
    if (pos > n) return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
            visited[i] = true;
            count += countArrangementHelper(n, pos + 1, visited);
            visited[i] = false;
        }
    }
    return count;
}

int countArrangement(int n) {
    vector<bool> visited(n + 1, false);
    return countArrangementHelper(n, 1, visited);
}

// Distribute Repeating Integers
bool canDistributeHelper(vector<int>& nums, vector<int>& quantities, int index) {
    if (index == quantities.size()) return true;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= quantities[index]) {
            nums[i] -= quantities[index];
            if (canDistributeHelper(nums, quantities, index + 1)) return true;
            nums[i] += quantities[index];
        }
    }
    return false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantities) {
    vector<int> freq(1001, 0);
    for (int num : nums) freq[num]++;
    vector<int> uniqueFreq;
    for (int count : freq) if (count > 0) uniqueFreq.push_back(count);
    sort(quantities.begin(), quantities.end(), greater<int>());
    return canDistributeHelper(uniqueFreq, quantities, 0);
}

int main() {
    // Test Combination Sum - II
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto combSum2 = combinationSum2(candidates, target);
    cout << "Combination Sum - II Results:\n";
    for (const auto& vec : combSum2) {
        for (int num : vec) cout << num << " ";
        cout << "\n";
    }

    // Test Permutation - II
    vector<int> nums = {1, 1, 2};
    auto permuteRes = permuteUnique(nums);
    cout << "\nPermutation - II Results:\n";
    for (const auto& vec : permuteRes) {
        for (int num : vec) cout << num << " ";
        cout << "\n";
    }

    // Test Beautiful Arrangement
    int n = 4;
    cout << "\nBeautiful Arrangement Count: " << countArrangement(n) << "\n";

    // Test Distribute Repeating Integers
    vector<int> numsToDistribute = {1, 2, 3, 3};
    vector<int> quantities = {2, 2};
    cout << "\nDistribute Repeating Integers Possible: " << (canDistribute(numsToDistribute, quantities) ? "Yes" : "No") << "\n";

    return 0;
}
