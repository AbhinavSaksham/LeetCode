class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        // Count frequency of each character
        for(char c : s)
            freq[c - 'a']++;

        string left = "";
        string mid = "";

        // Build left half in lexicographical order
        for(int i = 0; i < 26; i++) {

            left += string(freq[i] / 2, char('a' + i));

            // Odd frequency character goes in the middle
            if(freq[i] % 2)
                mid = char('a' + i);
        }

        // Right half is reverse of left
        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};