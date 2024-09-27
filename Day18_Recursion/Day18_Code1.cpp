#include <iostream>
#include <string>
using namespace std;

// ispalindrome function to check if a string is a palindrome
bool ispalindrome(string &str, int s, int e) {
    if (s >= e) {  // base case for the recursion, checking until the middle of the string
        return true;
    }

    if (str[s] != str[e]) {  // if characters don't match, it's not a palindrome
        return false;
    }

    return ispalindrome(str, s + 1, e - 1);  // recursive call moving towards the center
}

// sumDigits function to compute the sum of the digits of a number
void sumDigits(int n, int& sum) {
    if (n > 0) {
        int digit = n % 10;
        sum += digit;  // add the last digit to sum
        sumDigits(n / 10, sum);  // recursive call with the remaining digits
    }
}

int main() {
    // Test for palindrome
    string str = "janviivnaj";
    bool result = ispalindrome(str, 0, str.length() - 1);
    if (result) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    // Test for sum of digits
    int sum = 0;
    int n = 71288;
    sumDigits(n, sum);
    cout << "Sum of the digits of " << n << " is: " << sum << endl;

    return 0;
}
