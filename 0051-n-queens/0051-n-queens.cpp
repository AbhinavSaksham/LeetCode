class Solution {
public:

    vector<vector<string>> ans;

    // Track occupied columns and diagonals
    unordered_set<int> cols;
    unordered_set<int> diag1; // row - col
    unordered_set<int> diag2; // row + col

    void solve(int row, int n, vector<string>& board) {

        // All rows filled -> valid solution
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in current row
        for(int col = 0; col < n; col++) {

            // Check if column or diagonal is already occupied
            if(cols.count(col) ||
               diag1.count(row - col) ||
               diag2.count(row + col)) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';

            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            // Move to next row
            solve(row + 1, n, board);

            // Backtrack: remove queen
            board[row][col] = '.';

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        // Create empty board
        vector<string> board(n, string(n, '.'));

        solve(0, n, board);

        return ans;
    }
};