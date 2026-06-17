class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;      // Starting index of longest palindrome
        int maxLen = 1;     // Length of longest palindrome

        for(int i = 0; i < s.size(); i++) {

            // Check odd length palindrome
            int left = i;
            int right = i;

            while(left >= 0 &&
                  right < s.size() &&
                  s[left] == s[right]) {

                if(right - left + 1 > maxLen) {

                    maxLen = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }

            // Check even length palindrome
            left = i;
            right = i + 1;

            while(left >= 0 &&
                  right < s.size() &&
                  s[left] == s[right]) {

                if(right - left + 1 > maxLen) {

                    maxLen = right - left + 1;
                    start = left;
                }

                left--;
                right++;
            }
        }

        // Return longest palindromic substring
        return s.substr(start, maxLen);
    }
};