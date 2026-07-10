class Solution {
public:
    bool validPalindrome(string s) {


        //if (s.length() == 0 || )

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            if (s[left] == s[right]) {
                left++; //move front 
                right--; //move back
            }
            else {

                // Skip left character OR skip right character
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }

        return true;
    }
    private:

        bool isPalindrome(string &s, int left, int right) {

        while (left < right) {
            if (s[left] != s[right]) {
                return false; //char mismatch
            }
            left++; //move front
            right--; //move back
        }
        return true;
    }
};