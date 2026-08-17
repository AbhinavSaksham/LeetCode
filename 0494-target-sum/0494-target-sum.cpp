class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        solve(nums, 0, 0, target);
        return count;
    }

private:

    int count = 0;
    void solve(vector<int>& nums, int index, int sum, int target) {

        // All numbers have been used
        if(index == nums.size()) {

            // Found one valid expression
            if(sum == target) {
                count++;
            }
            return;
        }
        // Choose '+'
        solve(nums, index + 1, sum + nums[index], target);
        // Choose '-'
        solve(nums, index + 1, sum - nums[index], target);
        
    }
};