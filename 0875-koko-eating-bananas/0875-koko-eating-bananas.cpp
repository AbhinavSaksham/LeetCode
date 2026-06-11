class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible speed
        int start = 1;

        // Maximum possible speed
        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            long long hours = 0;

            // Calculate total hours needed at speed = mid
            for(int i = 0; i < piles.size(); i++) {

                hours += (piles[i] + mid - 1) / mid;
            }

            // Can finish within h hours
            if(hours <= h) {

                ans = mid;

                // Try smaller speed
                end = mid - 1;
            }
            else {

                // Need faster speed
                start = mid + 1;
            }
        }

        return ans;
    }
};