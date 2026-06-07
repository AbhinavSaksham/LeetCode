class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> rows[9]; //set because it doesn't contain duplicate
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r = 0; r < 9; r++) { //row

            for(int c = 0; c < 9; c++) { //col

                if(board[r][c] == '.') { //if empty, skip
                    continue;
                }

                char num = board[r][c]; //store curr digit

                int box = (r / 3) * 3 + (c / 3);

                if(rows[r].count(num) || //check duplicate  
                   cols[c].count(num) ||
                   boxes[box].count(num)) {

                    return false;
                }

                rows[r].insert(num); //insert if not duplicate
                cols[c].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};