class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end()); //sorting 
        vector<int> temp; // temp arr
        solve(0, nums, temp); // fn
        return ans; // solu
    }

    vector<vector<int>> ans; // final array

    void solve(int index, vector<int>& nums, vector<int>& temp) {

        ans.push_back(temp);

        // if(index == nums.size()){
        //     return;
        // }

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);
            solve(i + 1, nums, temp);
            temp.pop_back();
        }
    }
};