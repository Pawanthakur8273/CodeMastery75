#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function for Count Sort
string CountSort(string str) {
    vector<int> count(26, 0);
    for(int i = 0; i < str.size(); i++) {
        int idx = str[i] - 'a';
        count[idx]++;
    }

    int j = 0;
    for(int i = 0; i < count.size(); i++) {
        int num = count[i];
        while(num--) {
            str[j] = i + 'a';
            j++;
        }
    }
    return str;
}

// Function to check if two strings are anagrams
bool isAnagram(string str1, string str2) {
    vector<int> freq(26, 0);
    if(str1.length() != str2.length()) {
        return false;
    }

    int i = 0; 
    while(i < str1.length()) {
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
        i++;
    }

    for(int i = 0; i < freq.size(); i++) {
        if(freq[i] != 0) return false;
    }
    return true;
}

// Function to check if two strings are isomorphic
bool isIsomorphic(string str1, string str2) {
    vector<int> vec1(26, -1);
    vector<int> vec2(26, -1);

    if(str1.length() != str2.length()) {
        return false;
    }

    for(int i = 0; i < str1.length(); i++) {
        if(vec1[str1[i]-'a'] != vec2[str2[i]-'a']) {
            return false;
        }
        vec1[str1[i]-'a'] = vec2[str2[i]-'a'] = i;
    }
    return true;
}

// Function to find the longest common prefix in a vector of strings
string LongestCommonPrefix(vector<string>& str) {
    sort(str.begin(), str.end());
    string s1 = str[0];
    string s2 = str[str.size() - 1];

    int i = 0, j = 0;
    string ans = ""; 
    while(i < s1.length() && j < s2.length()) {
        if(s1[i] == s2[j]) {
            ans += s1[i];
            i++, j++;
        }
        else {
            break;
        }
    }
    return ans;
}

// Function to decode a string like "3[a]2[bc]" -> "aaabcbc"
string DecodeString(string str) {
    string result = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ']') {
            result.push_back(str[i]);
        }
        else {
            string s = "";
            while(!result.empty() && result.back() != '[') {
                s.push_back(result.back());
                result.pop_back();
            }
            reverse(s.begin(), s.end());
            result.pop_back();

            string num = "";
            while(!result.empty() && (result.back() >= '0' && result.back() <= '9')) {
                num.push_back(result.back());
                result.pop_back();
            }
            reverse(num.begin(), num.end());
            int int_num = stoi(num);
            while(int_num) {
                result += s;
                int_num--;
            }
        }
    }
    return result;
}

int main() {
    // Test isAnagram
    string str1 = "listen";
    string str2 = "silent";
    if (isAnagram(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    // Test CountSort
    string str3 = "programming";
    cout << "Count Sorted string: " << CountSort(str3) << endl;

    // Test isIsomorphic
    string str4 = "paper";
    string str5 = "title";
    if (isIsomorphic(str4, str5)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    // Test LongestCommonPrefix
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << LongestCommonPrefix(strs) << endl;

    // Test DecodeString
    string encodedStr = "3[a]2[bc]";
    cout << "Decoded string: " << DecodeString(encodedStr) << endl;

    return 0;
}
