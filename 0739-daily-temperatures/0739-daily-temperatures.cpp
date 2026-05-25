class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> result(n, 0);

        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller or equal temperatures
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i]) {

                st.pop();
            }

            // If stack not empty, warmer day exists
            if (!st.empty()) {

                result[i] = st.top() - i;
            }

            // Push current index
            st.push(i);
        }

        return result;
    }
};