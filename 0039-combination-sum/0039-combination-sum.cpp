class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve (0, candidates, target,temp, 0);
        return ans;
    }
    vector<vector<int>> ans; //store response from solve

    void solve(int index, vector<int>& candidates, int target, vector<int>& temp, int sum){
        if (sum == target){
        ans.push_back(temp); //temp me store karna is very imp
        return;
        }

         if(index == candidates.size() || sum > target) { // invalid input check 
            return;
        }

        temp.push_back(candidates[index]);
        solve(index, candidates, target, temp, sum + candidates[index]);
        temp.pop_back();

          // Exclude current element
        solve(index + 1, candidates, target, temp, sum);
    }
};