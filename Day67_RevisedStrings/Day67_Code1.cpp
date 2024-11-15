#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// 1. Valid Anagram
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : t) {
        count[c]--;
        if (count[c] < 0) return false;
    }
    return true;
}

// 2. Reverse Only Letters
string reverseOnlyLetters(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (!isalpha(s[left])) left++;
        else if (!isalpha(s[right])) right--;
        else swap(s[left++], s[right--]);
    }
    return s;
}

// 3. Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

// 4. Reverse Vowels Of A String
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string reverseVowels(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (!isVowel(s[left])) left++;
        else if (!isVowel(s[right])) right--;
        else swap(s[left++], s[right--]);
    }
    return s;
}

// 5. Isomorphic Strings
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, char> mapST, mapTS;
    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];
        if ((mapST.count(c1) && mapST[c1] != c2) || (mapTS.count(c2) && mapTS[c2] != c1))
            return false;
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }
    return true;
}

// 6. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto it : mp) {
        result.push_back(it.second);
    }
    return result;
}

// 7. Longest Palindromic Substring
string longestPalindrome(string s) {
    if (s.empty()) return "";
    int n = s.length(), start = 0, maxLength = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Check for substring of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }

    return s.substr(start, maxLength);
}

// Main function to test all the implemented functions
int main() {
    // Testing Valid Anagram
    string s1 = "anagram", t1 = "nagaram";
    cout << "Valid Anagram: " << (isAnagram(s1, t1) ? "True" : "False") << endl;

    // Testing Reverse Only Letters
    string s2 = "a-bC-dEf-ghIj";
    cout << "Reverse Only Letters: " << reverseOnlyLetters(s2) << endl;

    // Testing Longest Common Prefix
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    // Testing Reverse Vowels Of A String
    string s3 = "hello";
    cout << "Reverse Vowels Of A String: " << reverseVowels(s3) << endl;

    // Testing Isomorphic Strings
    string s4 = "egg", t4 = "add";
    cout << "Isomorphic Strings: " << (isIsomorphic(s4, t4) ? "True" : "False") << endl;

    // Testing Group Anagrams
    vector<string> strs2 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs2);
    cout << "Group Anagrams: ";
    for (auto group : groupedAnagrams) {
        cout << "[ ";
        for (string word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Testing Longest Palindromic Substring
    string s5 = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s5) << endl;

    return 0;
}
