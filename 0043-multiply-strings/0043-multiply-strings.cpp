class Solution {
public:
    string multiply(string num1, string num2) {

        // If either number is 0
        if(num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = num1.size();
        int m = num2.size();

        // Store  multiply result
        vector<int> result(n + m, 0);

        // Multiply each digit
        for(int i = n - 1; i >= 0; i--) {

            for(int j = m - 1; j >= 0; j--) {

                int x = num1[i] - '0';
                int y = num2[j] - '0';

                // Add product at correct position
                result[i + j + 1] += x * y;
            }
        }

        // Handle carry
        for(int i = n + m - 1; i > 0; i--) {

            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }

        // Convert to string
        string ans;

        // Skip leading zeros
        int i = 0;
        while(i < result.size() && result[i] == 0) {
            i++;
        }

        while(i < result.size()) {
            ans += char(result[i] + '0');
            i++;
        }

        return ans;
    }
};