#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

// Problem 1: Integer to English Words
vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string helper(int num) {
    if (num == 0) return "";
    else if (num < 20) return below_20[num] + " ";
    else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
    else return below_20[num / 100] + " Hundred " + helper(num % 100);
}

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string result;
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) result = helper(num % 1000) + thousands[i] + " " + result;
        num /= 1000;
        i++;
    }
    return result;
}

// Problem 2: Wild Card Matching
bool isMatch(string s, string p, int i = 0, int j = 0) {
    if (j == p.size()) return i == s.size();
    if (p[j] == '*') {
        return isMatch(s, p, i, j + 1) || (i < s.size() && isMatch(s, p, i + 1, j));
    }
    return i < s.size() && (s[i] == p[j] || p[j] == '?') && isMatch(s, p, i + 1, j + 1);
}

// Problem 3: Number of Dice Rolls With Target Sum
int numRollsToTarget(int d, int f, int target) {
    if (target < 0) return 0;
    if (d == 0) return target == 0 ? 1 : 0;
    int ways = 0;
    for (int i = 1; i <= f; i++) {
        ways += numRollsToTarget(d - 1, f, target - i);
    }
    return ways;
}

// Problem 4: Perfect Squares
int minSquares(int n) {
    if (n <= 0) return 0;
    int min_count = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
        min_count = min(min_count, 1 + minSquares(n - i * i));
    }
    return min_count;
}

// Problem 5: Minimum Cost for Tickets
int minCostTicketsHelper(vector<int>& days, vector<int>& costs, int index) {
    if (index >= days.size()) return 0;

    int oneDayPass = costs[0] + minCostTicketsHelper(days, costs, index + 1);

    int i;
    for (i = index; i < days.size() && days[i] < days[index] + 7; i++);
    int sevenDayPass = costs[1] + minCostTicketsHelper(days, costs, i);

    for (i = index; i < days.size() && days[i] < days[index] + 30; i++);
    int thirtyDayPass = costs[2] + minCostTicketsHelper(days, costs, i);

    return min(oneDayPass, min(sevenDayPass, thirtyDayPass));
}

int minCostTickets(vector<int>& days, vector<int>& costs) {
    return minCostTicketsHelper(days, costs, 0);
}

int main() {
    // Testing Problem 1
    cout << "Integer to English Words: " << numberToWords(12345) << endl;

    // Testing Problem 2
    cout << "Wild Card Matching: " << (isMatch("aa", "a*") ? "true" : "false") << endl;

    // Testing Problem 3
    cout << "Number of Dice Rolls With Target Sum: " << numRollsToTarget(2, 6, 7) << endl;

    // Testing Problem 4
    cout << "Perfect Squares: " << minSquares(12) << endl;

    // Testing Problem 5
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << "Minimum Cost for Tickets: " << minCostTickets(days, costs) << endl;

    return 0;
}
