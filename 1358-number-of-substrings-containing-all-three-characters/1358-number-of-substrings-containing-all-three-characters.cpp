class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();

        vector<int> freq(3, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Add current character
            freq[s[right] - 'a']++;

            // Window contains a, b and c
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                // Count all valid substrings
                ans += n - right;

                // Shrink window
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};