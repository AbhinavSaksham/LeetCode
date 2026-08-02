class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currEnd = 0;   // End of current jump range
        int farthest = 0;  // Farthest index reachable

        // No need to process the last index
        for (int i = 0; i < nums.size() - 1; i++) {

            // Update the farthest position we can reach
            farthest = max(farthest, i + nums[i]);

            // End of current range -> take a jump
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};