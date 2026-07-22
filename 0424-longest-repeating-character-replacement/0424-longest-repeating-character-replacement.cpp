class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;  // Add current character

            // Maximum frequency character in current window
            maxFreq = max(maxFreq, mp[s[right]]);

            // If replacements needed > k, shrink window
            while ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1); // Update answer
        }

        return ans;
    }
};