
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
using namespace std;

// 1. Reverse a String
void reverseString(string &str) {
    reverse(str.begin(), str.end());
    cout << "Reversed String: " << str << endl;
}

// 2. Check Palindrome
bool isPalindrome(const string &str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++; right--;
    }
    return true;
}

// 3. Count Vowels and Consonants
void countVowelsConsonants(const string &str) {
    int vowels = 0, consonants = 0;
    for (char ch : str) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
}

// 4. Remove Duplicates from String
string removeDuplicates(const string &str) {
    set<char> seen;
    string result;
    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    return result;
}

// 5. Longest Substring Without Repeating Characters
int longestUniqueSubstring(const string &str) {
    vector<int> lastIndex(256, -1);
    int maxLength = 0, start = 0;
    for (int end = 0; end < str.size(); end++) {
        start = max(start, lastIndex[str[end]] + 1);
        maxLength = max(maxLength, end - start + 1);
        lastIndex[str[end]] = end;
    }
    return maxLength;
}

// 6. String to Integer Conversion (Custom Implementation of `atoi`)
int customAtoi(const string &str) {
    int result = 0, sign = 1, i = 0;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    for (; i < str.size(); i++) {
        if (!isdigit(str[i])) break;
        result = result * 10 + (str[i] - '0');
    }
    return result * sign;
}

// 7. Find All Permutations of a String
void printPermutations(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            printPermutations(str, l + 1, r);
            swap(str[l], str[i]); // Backtrack
        }
    }
}

// 8. Check Anagram
bool areAnagrams(const string &str1, const string &str2) {
    if (str1.size() != str2.size()) return false;
    string s1 = str1, s2 = str2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// 9. Replace Spaces with %20 (URLify)
string urlify(const string &str) {
    string result;
    for (char ch : str) {
        if (ch == ' ')
            result += "%20";
        else
            result += ch;
    }
    return result;
}

// 10. Longest Common Prefix
string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

// Main function to demonstrate all programs
int main() {
    string str1, str2;
    vector<string> stringList;

    // 1. Reverse a String
    cout << "Enter a string to reverse: ";
    getline(cin, str1);
    reverseString(str1);

    // 2. Check Palindrome
    cout << "Enter a string to check palindrome: ";
    getline(cin, str1);
    cout << (isPalindrome(str1) ? "Palindrome" : "Not Palindrome") << endl;

    // 3. Count Vowels and Consonants
    cout << "Enter a string to count vowels and consonants: ";
    getline(cin, str1);
    countVowelsConsonants(str1);

    // 4. Remove Duplicates from String
    cout << "Enter a string to remove duplicates: ";
    getline(cin, str1);
    cout << "After removing duplicates: " << removeDuplicates(str1) << endl;

    // 5. Longest Substring Without Repeating Characters
    cout << "Enter a string to find longest unique substring: ";
    getline(cin, str1);
    cout << "Length of longest unique substring: " << longestUniqueSubstring(str1) << endl;

    // 6. String to Integer Conversion (Custom atoi)
    cout << "Enter a string to convert to integer: ";
    getline(cin, str1);
    cout << "Integer value: " << customAtoi(str1) << endl;

    // 7. Find All Permutations of a String
    cout << "Enter a string to find all permutations: ";
    getline(cin, str1);
    cout << "Permutations:\n";
    printPermutations(str1, 0, str1.size() - 1);

    // 8. Check Anagram
    cout << "Enter two strings to check if they are anagrams:\n";
    cout << "String 1: ";
    getline(cin, str1);
    cout << "String 2: ";
    getline(cin, str2);
    cout << (areAnagrams(str1, str2) ? "Anagrams" : "Not Anagrams") << endl;

    // 9. Replace Spaces with %20
    cout << "Enter a string to URLify: ";
    getline(cin, str1);
    cout << "URLified String: " << urlify(str1) << endl;

    // 10. Longest Common Prefix
    cout << "Enter number of strings for longest common prefix: ";
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after integer input
    stringList.resize(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, stringList[i]);
    }
    cout << "Longest Common Prefix: " << longestCommonPrefix(stringList) << endl;

    return 0;
}
