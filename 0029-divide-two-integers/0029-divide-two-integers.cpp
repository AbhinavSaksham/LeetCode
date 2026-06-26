class Solution {
public:
    int divide(int dividend, int divisor) {

        // Handle overflow case
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the answer
        bool negative =
            (dividend < 0) ^ (divisor < 0);

        // Convert to positive using long long
        long long dvd = labs((long long)dividend);
        long long dvs = labs((long long)divisor);

        long long ans = 0;

        // Keep subtracting largest possible multiple
        while(dvd >= dvs) {

            long long temp = dvs;
            long long multiple = 1;

            // Double divisor until it exceeds dividend
            while((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }

        // Apply sign
        if(negative) {
            ans = -ans;
        }

        return (int)ans;
    }
};