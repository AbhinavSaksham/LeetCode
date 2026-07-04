class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxi = INT_MIN;   // Store maximum subarray sum

        for (int i = 0; i < nums.size(); i++) {

            // Add current element
            sum += nums[i];

            // Update maximum sum
            maxi = max(maxi, sum);

            // If sum becomes negative, start a new subarray
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         int sum = 0;
//         int maxi = INT_MIN;

//         int start = 0;      // Current subarray start
//         int ansStart = 0;   // Answer start index
//         int ansEnd = 0;     // Answer end index

//         for (int i = 0; i < nums.size(); i++) {

//             // Start a new subarray
//             if (sum == 0) {
//                 start = i;
//             }

//             sum += nums[i]; // Add current element

//             if (sum > maxi) {  // Update maximum sum
//                 maxi = sum;
//                 ansStart = start;
//                 ansEnd = i;
//             }

//             if (sum < 0) { // Reset if sum becomes negative
//                 sum = 0;
//             }
//         }

//         // Optional: print the subarray
//         /*
//         for (int i = ansStart; i <= ansEnd; i++) {
//             cout << nums[i] << " ";
//         }
//         */
//         return maxi;
//     }
// };