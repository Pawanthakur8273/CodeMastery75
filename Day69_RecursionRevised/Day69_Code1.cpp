#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 1. Subsets Generation (Power Set)
void generateSubsets(vector<int> &nums, vector<int> &current, int index) {
    if (index == nums.size()) {
        cout << "{ ";
        for (int num : current) cout << num << " ";
        cout << "}\n";
        return;
    }
    generateSubsets(nums, current, index + 1); // Exclude current element
    current.push_back(nums[index]);           // Include current element
    generateSubsets(nums, current, index + 1);
    current.pop_back();                       // Backtrack
}

// 2. Word Break Problem
bool wordBreak(string s, unordered_set<string> &wordDict, int start) {
    if (start == s.size()) return true;
    for (int end = start + 1; end <= s.size(); ++end) {
        if (wordDict.count(s.substr(start, end - start)) &&
            wordBreak(s, wordDict, end)) {
            return true;
        }
    }
    return false;
}

// 3. N-Queens Problem
bool isSafe(vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
        if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false;
    }
    return true;
}

void solveNQueens(vector<string> &board, int row, int n) {
    if (row == n) {
        for (const auto &line : board) cout << line << endl;
        cout << endl;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n);
            board[row][col] = '.'; // Backtrack
        }
    }
}

// 4. Sudoku Solver
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == c || board[i][col] == c ||
            board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; ++c) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.'; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// 5. Permutations of a String
void permute(string s, int l, int r) {
    if (l == r) {
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]); // Backtrack
    }
}

int main() {
    // Problem 1: Subsets Generation
    cout << "1. Subsets Generation:\n";
    vector<int> nums = {1, 2, 3};
    vector<int> current;
    generateSubsets(nums, current, 0);
    
    // Problem 2: Word Break
    cout << "\n2. Word Break Problem:\n";
    unordered_set<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    cout << (wordBreak(s, wordDict, 0) ? "Yes" : "No") << endl;

    // Problem 3: N-Queens
    cout << "\n3. N-Queens Problem (for 4x4 board):\n";
    int n = 4;
    vector<string> board(n, string(n, '.'));
    solveNQueens(board, 0, n);

    // Problem 4: Sudoku Solver
    cout << "\n4. Sudoku Solver:\n";
    vector<vector<char>> sudokuBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if (solveSudoku(sudokuBoard)) {
        for (const auto &row : sudokuBoard) {
            for (char c : row) cout << c << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists\n";
    }

    // Problem 5: Permutations of a String
    cout << "\n5. Permutations of a String:\n";
    string str = "ABC";
    permute(str, 0, str.size() - 1);

    return 0;
}
