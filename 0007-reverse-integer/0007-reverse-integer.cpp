class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while (x != 0) {

            int digit = x % 10; //1st step

             // Check positive overflow -->base case check 
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return 0;
            // Check negative overflow
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
                return 0;

            
            rev = rev * 10 + digit; // Build reversed number 2nd step
            x /= 10; // Remove last digit 3rd step
        }

        return rev;
    }
};