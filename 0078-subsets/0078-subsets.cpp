class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }

    vector<vector<int>> ans; //to store all the subset 

    void solve(int index, //traversal point 
               vector<int>& nums,   //org
               vector<int>& temp) { //sub sets

        // store current subset
        ans.push_back(temp);

        for(int i = index; i < nums.size(); i++) {

            temp.push_back(nums[i]);            // choose
            solve(i + 1, nums, temp);              // explore
            temp.pop_back();              // backtrack
        }
    }

};