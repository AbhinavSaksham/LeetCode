class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1) { //base case
            return x;
        }

        int start = 1;
        int end = x;
        int ans = 0;

        while (start <= end) {

            long long mid = start + (end - start) / 2; //mid of x 

            if (mid * mid == x) { // Perfect square
                return mid;
            }

            else if (mid * mid < x) {
                ans = mid;
                start = mid + 1; // Move right
            }

            else {
                end = mid - 1; // Move left
            }
        }

        return ans;
    }
};