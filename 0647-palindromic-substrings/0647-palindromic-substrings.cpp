class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();
        int ans = 0;

        // Check every possible center
        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            int l = i, r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};