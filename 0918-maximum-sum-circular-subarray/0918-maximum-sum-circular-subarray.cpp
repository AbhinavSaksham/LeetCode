class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int sumMax = 0;
        int sumMin = 0;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            total += nums[i];

            // Maximum subarray
            sumMax += nums[i];
            maxi = max(maxi, sumMax);

            if (sumMax < 0) {
                sumMax = 0;
            }

            // Minimum subarray
            sumMin += nums[i];
            mini = min(mini, sumMin);

            if (sumMin > 0) {
                sumMin = 0;
            }
        }

        // All elements are negative
        if (maxi < 0) {
            return maxi;
        }

        // Return maximum of normal and circular subarray
        return max(maxi, total - mini);
    }
};

// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
        
//         int sum = 0;
//         int maxi = INT_MIN;

//         for (int i = 0; i < nums.size(); i++){

//             sum += nums[i];

//             maxi = max(maxi, sum);

//             if (sum < 0){
//                 sum = 0;
//             }
//         }
//         return maxi;
//     }
// };