class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp; //declare map 

        long long sum = 0;
        long long maxi = 0;

        int i = 0; //pointer1
        int j = 0; //pointer2

        while (j < nums.size()) { //j goes to last index of the array

            sum += nums[j]; //each time sum happens until windows = k 

            mp[nums[j]]++;

            if (j - i + 1 == k) { // Window size becomes k

                // All elements distinct
                if (mp.size() == k) {
                    maxi = max(maxi, sum);
                }

                // Remove left element
                sum -= nums[i];

                mp[nums[i]]--;

                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                i++;  //increrment i for next window
            }

            j++;   //increrment j for next window
        }

        return maxi;
    }
};