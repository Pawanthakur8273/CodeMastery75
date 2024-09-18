#include <iostream>
#include <string>  // To use the string class
using namespace std;

// Function to remove adjacent duplicate characters
string RemoveAdj(string &str) {
  string ans = "";  // Initialize an empty string to store the result

  // If the input string is not empty, add the first character to 'ans'
  if (!str.empty()) {
    ans.push_back(str[0]);
  }

  int j = 0;  // Initialize a pointer 'j' for tracking the 'ans' string

  // Loop through the string starting from the second character
  for (int i = 1; i < str.length(); i++) {
    // If the last character in 'ans' is different from the current character
    if (ans[j] != str[i]) {
      ans.push_back(str[i]);  // Add current character to 'ans'
      j++;  // Move the pointer 'j' to the next position
    }
    else {
      // If current character is the same as the last character in 'ans'
      ans.pop_back();  // Remove the last character (which is a duplicate)
      j--;  // Move the pointer 'j' back by one position
    }
  }
  
  return ans;  // Return the result string with adjacent duplicates removed
}

// Function to remove all occurrences of a substring from a string
void RemoveAllOccOfSubString(string& str, string& toRemove) {
  // Find the first occurrence of the substring 'toRemove' in 'str'
  size_t found = str.find(toRemove);

  // While the substring is found in 'str'
  while (found != string::npos) {
    // Erase the substring from 'str' starting at index 'found'
    str.erase(found, toRemove.length());
    // Find the next occurrence of 'toRemove' in 'str'
    found = str.find(toRemove);
  }
}

int main() {
  string str = "axxxxyyyyb";  // Initialize a test string
  
  // Function call to remove adjacent duplicates (currently commented out)
  // cout << RemoveAdj(str) << endl;

  string toRemove = "xy";  // Substring to remove from 'str'
  
  // Function call to remove all occurrences of "xy" from 'str'
  RemoveAllOccOfSubString(str, toRemove);
  
  // Output the final string after removing the substring
  cout << str << endl;

  return 0;
}
