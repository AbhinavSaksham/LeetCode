class Solution {
public:
    vector<string> generateParenthesis(int n) {
    
        vector<string> ans;
        createP(0, 0, n, "", ans);
        return ans;
    }

  private:
  void createP(int open, int close, int n, string temp, vector<string>& ans) {

        if (open == n && open == close){ //base case
            ans.push_back(temp);
            return;
        }
          // Add '(' if we still can
        if (open < n) {
            createP(open + 1, close, n, temp + "(", ans);
        }
        // Add ')' only if it is valid
        if (close < open) {
            createP(open, close + 1, n, temp + ")", ans);
        }
    }
};