class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        for(int r = 0; r < 9; r++) { //for row

            unordered_set<char> s; 
            for(int c = 0; c < 9; c++) { //move towards right

                if(board[r][c] == '.') { //if empty, skip
                    continue;
                }
                if(s.count(board[r][c])) { //if present, return false
                    return false;
                }
                s.insert(board[r][c]); //else insert 
            }
        }

        for(int c = 0; c < 9; c++) { //for col

            unordered_set<char> s;
            for(int r = 0; r < 9; r++) { //move down

                if(board[r][c] == '.') { //if empty, skip
                    continue;
                }
                if(s.count(board[r][c])) { // if val present, falseee
                    return false;
                }
                s.insert(board[r][c]); //else insert in set
            }
        }

        for(int box = 0; box < 9; box++) { //for  3*3 boxes

            unordered_set<char> s;

            int smallRow = (box / 3) * 3; //row
            int smallCol = (box % 3) * 3; //col

            for(int r = smallRow; r < smallRow + 3; r++) { // row
                for(int c = smallCol; c < smallCol + 3; c++) { //col

                    if(board[r][c] == '.') {
                    continue;
                    }

                    if(s.count(board[r][c])) {
                    return false;
                    }

                    s.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
























// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {

//         unordered_set<char> rows[9]; //set because it doesn't contain duplicate
//         unordered_set<char> cols[9];
//         unordered_set<char> boxes[9];

//         for(int r = 0; r < 9; r++) { //row


//             for(int c = 0; c < 9; c++) { //col

//                 if(board[r][c] == '.') { //if empty, skip
//                     continue;
//                 }

//                 char num = board[r][c]; //store curr digit

//                 int box = (r / 3) * 3 + (c / 3);

//                 if(rows[r].count(num) || //check duplicate  
//                    cols[c].count(num) ||
//                    boxes[box].count(num)) {

//                     return false;
//                 }

//                 rows[r].insert(num); //insert if not duplicate
//                 cols[c].insert(num);
//                 boxes[box].insert(num);
//             }
//         }

//         return true;
//     }
// };