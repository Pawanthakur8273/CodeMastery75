#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 1. House Robber Problem
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = 0, prev1 = 0, curr = 0;
    for (int i = 0; i < n; ++i) {
        curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// 2. Integer to English Words
vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string helper(int num) {
    if (num == 0) return "";
    if (num < 20) return below_20[num] + " ";
    if (num < 100) return tens[num / 10] + " " + helper(num % 10);
    if (num < 1000) return below_20[num / 100] + " Hundred " + helper(num % 100);
    return "";
}

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string result = "";
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            result = helper(num % 1000) + thousands[i] + " " + result;
        }
        num /= 1000;
        i++;
    }
    while (result.back() == ' ') result.pop_back();
    return result;
}

// 3. Wild Card Matching
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}

// 4. Number Of Dice Rolls With Target Sum
int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    int MOD = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            for (int face = 1; face <= k; face++) {
                if (j >= face) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                }
            }
        }
    }
    return dp[n][target];
}

// 5. Perfect Squares
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    // Test House Robber Problem
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "House Robber Maximum Amount: " << rob(nums) << endl;

    // Test Integer to English Words
    int number = 1234567;
    cout << "Integer to English Words: " << numberToWords(number) << endl;

    // Test Wild Card Matching
    string s = "adceb";
    string p = "*a*b";
    cout << "Wild Card Matching: " << (isMatch(s, p) ? "True" : "False") << endl;

    // Test Number Of Dice Rolls With Target Sum
    int n = 2, k = 6, target = 7;
    cout << "Number Of Dice Rolls With Target Sum: " << numRollsToTarget(n, k, target) << endl;

    // Test Perfect Squares
    int num = 12;
    cout << "Perfect Squares: " << numSquares(num) << endl;

    return 0;
}
