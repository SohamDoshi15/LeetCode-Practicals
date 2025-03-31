#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> rows[9], cols[9], boxes[3][3];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.'){
                    continue; // Ignore empty cells
                }

                // Convert char to int key
                int digit = num - '0';

                // Check row, column, and box
                if (++rows[i][digit] > 1 || ++cols[j][digit] > 1 || ++boxes[i / 3][j / 3][digit] > 1) {
                    return false; // Found duplicate
                }
            }
        }
        
        return true; // No duplicates found
    }
};


int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << (sol.isValidSudoku(board) ? "Valid" : "Invalid") << endl;
    return 0;
}
