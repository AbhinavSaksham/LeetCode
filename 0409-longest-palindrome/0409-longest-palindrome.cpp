class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto &[ch, count] : freq) {

            // Use all characters if count is even
            if (count % 2 == 0) {
                length += count;
            }
            // Use count - 1 (largest even part)
            else {
                length += count - 1;
                hasOdd = true;
            }
        }

        // Place one odd character in the center
        if (hasOdd) {
            length++;
        }

        return length;
    }
};