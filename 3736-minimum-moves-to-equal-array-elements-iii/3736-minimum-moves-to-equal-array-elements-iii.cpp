class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Find the maximum element
        int maxi = *max_element(nums.begin(), nums.end());

        int ans = 0;

        // Increase every element to the maximum
        for(int i = 0; i < nums.size(); i++) {
            ans += maxi - nums[i];
        }

        return ans;
    }
};