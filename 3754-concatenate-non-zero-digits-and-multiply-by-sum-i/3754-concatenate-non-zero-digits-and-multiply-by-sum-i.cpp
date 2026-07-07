class Solution {
public:
    long long sumAndMultiply(int n) {

        vector<int> digits;

        // Extract non-zero digits
        while (n > 0) {

            int digit = n % 10;
            if (digit != 0) {
                digits.push_back(digit);
            }
            n /= 10;
        }

        long long x = 0;
        long long sum = 0;

        // Build number in original order
        for (int i = digits.size() - 1; i >= 0; i--) {

            x = x * 10 + digits[i];
            sum += digits[i];
        }

        return x * sum;
    }
};