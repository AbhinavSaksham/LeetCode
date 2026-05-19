class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            ans.push_back(nums[i]); //1st index

            ans.push_back(nums[i + n]); //nth index so, 0+3 = 3rd index i.e., 3
        }

        return ans; // ans[i] + ans[i+n] = [2,3, .....]
    }
};