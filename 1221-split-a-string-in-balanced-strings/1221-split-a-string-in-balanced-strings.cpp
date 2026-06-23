class Solution {
public:
    int balancedStringSplit(string s) {

        int balance = 0;
        int count = 0;

        for (char ch : s) {

            // Update balance
            if (ch == 'R')
                balance++;
            else
                balance--;

            // Found a balanced substring
            if (balance == 0)
                count++;
        }

        return count;
    }
};