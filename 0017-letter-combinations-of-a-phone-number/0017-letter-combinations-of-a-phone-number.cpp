class Solution {
public:

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current = "";
        solve(digits, 0, current, mapping);
        return ans;
    }

private: 

    vector<string> ans;
    void solve(string& digits, int index, string current, vector<string>& mapping) {

        // All digits are processed
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0']; // Get letters for current digit
       
        for(int i = 0; i < letters.size(); i++) {  // Try every possible letter

            current.push_back(letters[i]); // Choose
            solve(digits, index + 1, current, mapping); // Move to next digit
            current.pop_back(); // Backtrack
        }
    }
};