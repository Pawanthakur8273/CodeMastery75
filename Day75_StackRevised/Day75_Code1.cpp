
// Solutions to Stacks Problems from Day 75 of 75 Hard Coding Challenge

#include <bits/stdc++.h>
using namespace std;

// 1. Minimum Bracket Reversal
int minBracketReversal(string s) {
    if (s.length() % 2 != 0) return -1; // Odd length cannot be balanced
    stack<char> st;
    for (char ch : s) {
        if (ch == '}' && !st.empty() && st.top() == '{') {
            st.pop();
        } else {
            st.push(ch);
        }
    }
    int open = 0, close = 0;
    while (!st.empty()) {
        if (st.top() == '{') open++;
        else close++;
        st.pop();
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

// 2. Remove All Adjacent Duplicates In String
string removeDuplicates(string s) {
    stack<char> st;
    for (char ch : s) {
        if (!st.empty() && st.top() == ch) st.pop();
        else st.push(ch);
    }
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// 3. Celebrity Problem
int findCelebrity(vector<vector<int>> &matrix, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);
    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if (matrix[a][b] == 1) st.push(b);
        else st.push(a);
    }
    int candidate = st.top();
    for (int i = 0; i < n; i++) {
        if ((i != candidate && (matrix[candidate][i] == 1 || matrix[i][candidate] == 0))) return -1;
    }
    return candidate;
}

// 4. Next Greater Element in Linked List
vector<int> nextGreaterElements(vector<int> &arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        if (!st.empty()) result[i] = st.top();
        st.push(arr[i]);
    }
    return result;
}

// 5. N Stacks in an Array
class NStack {
    vector<int> arr, top, next;
    int freeSpot;
public:
    NStack(int N, int S) {
        arr.resize(S);
        top.resize(N, -1);
        next.resize(S);
        for (int i = 0; i < S - 1; i++) next[i] = i + 1;
        next[S - 1] = -1;
        freeSpot = 0;
    }
    bool push(int stackNo, int x) {
        if (freeSpot == -1) return false;
        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;
        next[index] = top[stackNo - 1];
        top[stackNo - 1] = index;
        return true;
    }
    int pop(int stackNo) {
        if (top[stackNo - 1] == -1) return -1;
        int index = top[stackNo - 1];
        top[stackNo - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

// 6. Online Stock Span
vector<int> stockSpan(vector<int> &prices) {
    vector<int> span(prices.size());
    stack<pair<int, int>> st;
    for (int i = 0; i < prices.size(); i++) {
        int days = 1;
        while (!st.empty() && st.top().first <= prices[i]) {
            days += st.top().second;
            st.pop();
        }
        st.push({prices[i], days});
        span[i] = days;
    }
    return span;
}

// 7. Check If Word Is Valid After Substitutions
bool isValidWord(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == 'c') {
            if (st.size() < 2 || st.top() != 'b') return false;
            st.pop();
            if (st.top() != 'a') return false;
            st.pop();
        } else {
            st.push(ch);
        }
    }
    return st.empty();
}

int main() {
    // Test Cases

    // 1. Minimum Bracket Reversal
    cout << "Minimum Bracket Reversal: " << minBracketReversal("}{{}}{{{") << endl;

    // 2. Remove All Adjacent Duplicates In String
    cout << "Remove Adjacent Duplicates: " << removeDuplicates("abbaca") << endl;

    // 3. Celebrity Problem
    vector<vector<int>> matrix = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << "Celebrity Index: " << findCelebrity(matrix, 3) << endl;

    // 4. Next Greater Element in Linked List
    vector<int> arr = {2, 7, 4, 3, 5};
    vector<int> nge = nextGreaterElements(arr);
    cout << "Next Greater Elements: ";
    for (int val : nge) cout << val << " ";
    cout << endl;

    // 5. N Stacks in an Array
    NStack stacks(3, 10);
    stacks.push(1, 15);
    stacks.push(2, 45);
    cout << "Popped from Stack 1: " << stacks.pop(1) << endl;

    // 6. Online Stock Span
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stockSpan(prices);
    cout << "Stock Span: ";
    for (int days : span) cout << days << " ";
    cout << endl;

    // 7. Check If Word Is Valid After Substitutions
    cout << "Is Valid Word: " << (isValidWord("aabcbc") ? "Yes" : "No") << endl;

    return 0;
}
