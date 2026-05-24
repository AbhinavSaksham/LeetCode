class Solution {
public:
    bool isPalindrome(string s) {

        std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); });

        s.erase(std::remove_if(s.begin(), s.end(), 
        [](unsigned char c) { return !std::isalnum(c); }), 
        s.end());

        int start = 0;
        int end = s.length() - 1;

        while (start < end) {

            if (s[start] != s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};