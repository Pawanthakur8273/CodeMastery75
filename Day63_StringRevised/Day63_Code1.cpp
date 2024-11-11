
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

// 1. Permutation in String (Problem 567)
class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> target(26, 0), now(26, 0);
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        
        for (char c : s1) target[c - 'a']++;
        for (int i = 0; i < m; i++) {
            now[s2[i] - 'a']++;
            if (i >= n) now[s2[i - n] - 'a']--;
            if (now == target) return true;
        }
        return false;
    }
};

// 2. Longest Substring Without Repeating Characters (Problem 3)
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int left = 0, maxLength = 0;
        for (int right = 0; right < s.size(); right++) {
            if (seen.find(s[right]) != seen.end())
                left = max(left, seen[s[right]] + 1);
            seen[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

// 3. Group Anagrams (Problem 49)
class Solution3 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& entry : map) {
            result.push_back(entry.second);
        }
        return result;
    }
};

// 4. Valid Palindrome II (Problem 680)
class Solution4 {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
        }
        return true;
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

// 5. Minimum Window Substring (Problem 76)
class Solution5 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target, window;
        for (char c : t) target[c]++;
        int left = 0, right = 0, valid = 0;
        int start = 0, minLength = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (target.count(c)) {
                window[c]++;
                if (window[c] == target[c]) valid++;
            }
            while (valid == target.size()) {
                if (right - left < minLength) {
                    start = left;
                    minLength = right - left;
                }
                char d = s[left];
                left++;
                if (target.count(d)) {
                    if (window[d] == target[d]) valid--;
                    window[d]--;
                }
            }
        }
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};

int main() {
    // Example usages
    Solution1 sol1;
    cout << sol1.checkInclusion("ab", "eidbaooo") << endl;  // Should return 1 (true)
    
    Solution2 sol2;
    cout << sol2.lengthOfLongestSubstring("abcabcbb") << endl;  // Should return 3
    
    Solution3 sol3;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol3.groupAnagrams(strs);
    for (auto& group : result) {
        for (auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    Solution4 sol4;
    cout << sol4.validPalindrome("abca") << endl;  // Should return 1 (true)

    Solution5 sol5;
    cout << sol5.minWindow("ADOBECODEBANC", "ABC") << endl;  // Should return "BANC"
    
    return 0;
}
