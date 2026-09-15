class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> candy(n, 1); // Everyone gets at least 1 candy

        // Check left to right
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // Check right to left
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int ans = 0;

        // Calculate total candies
        for(int i = 0; i < n; i++) {
            ans += candy[i];
        }

        return ans;
    }
};