#include <iostream>
#include<string>
#include<vector>
using namespace std;

// Function to sort characters in a string lexicographically
string CountSort(string str) {
    vector<int> vec(26, 0); // Create a frequency vector for characters
    for (int i = 0; i < str.length(); i++) {
        vec[str[i] - 'a']++; // Count occurrences of each character
    }
    int j = 0;
    for (int i = 0; i < vec.size(); i++) {
        int num = vec[i];
        while (num--) { // Replace characters in sorted order
            str[j] = i + 'a';
            j++;
        }
    }
    return str;
}

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int s = 0;
    int e = str.length() - 1;
    while (s <= e) {
        if (str[s] != str[e]) { // Compare characters from both ends
            return false;
        }
        s++;
        e--;
    }
    return true;
}

// Function to check if str2 is a subsequence of str1
bool checkSubSeq(string str1, string str2) {
    if (str2.length() > str1.length()) return false; // str2 can't be longer than str1
    int j = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == str2[j]) { // Match characters of str2 in str1
            j++;
        }
    }
    return j == str2.length(); // All characters of str2 were found in str1
}

// Function to find the index of the leftmost repeating character in a string
int findLeftMostRepeatingChar(string str) {
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) { // First repeating character found
                return i;
            }
        }
    }
    return -1; // No repeating character
}

// Optimized approach for finding the leftmost repeating character using frequency vector
int betterApproachForFindingLeftMostRepeatingChar(string str) {
    vector<int> vec(26, 0); // Frequency vector for characters
    for (int i = 0; i < str.length(); i++) {
        vec[str[i] - 'a']++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (vec[str[i] - 'a'] > 1) { // If the character repeats
            return i;
        }
    }
    return -1;
}

// Function to find the index of the leftmost non-repeating character in a string
int LeftMostNonRepeatingChar(string str) {
    vector<int> vec(26, 0); // Frequency vector for characters
    for (int i = 0; i < str.length(); i++) {
        vec[str[i] - 'a']++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (vec[str[i] - 'a'] == 1) { // If the character is non-repeating
            return i;
        }
    }
    return -1;
}

int main() {

    string str1;
    cout << "Enter string 1: ";
    getline(cin, str1); // Input string 1

    string str2;
    cout << "Enter string 2: ";
    cin >> str2; // Input string 2

    // Call and print results of each function
    cout << "Sorted string: " << CountSort(str1) << endl;
    cout << "Is palindrome: " << isPalindrome(str1) << endl;
    cout << "Is str2 a subsequence of str1: " << checkSubSeq(str1, str2) << endl;
    cout << "Index of leftmost repeating character: " << findLeftMostRepeatingChar(str1) << endl;
    cout << "Optimized approach for leftmost repeating character: " << betterApproachForFindingLeftMostRepeatingChar(str1) << endl;
    cout << "Leftmost non-repeating character index: " << LeftMostNonRepeatingChar(str1) << endl;

    return 0;
}
