class Solution {
public:

    int subsetXORSum(vector<int>& nums) {

        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }

    int ans = 0;

    void solve(int index, vector<int>& nums, vector<int>& temp) {

       
        if(index == nums.size()) {  // Base case check 

            int xr = 0;

            // Calculate XOR of current subset
            for(int num : temp) {
                xr ^= num;
            }
            
            ans = ans + xr;
            return;
        }
        
        temp.push_back(nums[index]); // Include current element
        solve(index + 1, nums, temp);
        temp.pop_back(); // Backtrack

        solve(index + 1, nums, temp); // Exclude current element
    }


};