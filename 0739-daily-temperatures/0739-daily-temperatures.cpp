class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
    
        vector<int> ans(n, 0);     // Answer array initialized with 0 lol

        stack<int> st;  // Stack stores indices

        for(int i = 0; i < n; i++) {

            // Current temperature is warmer than previous
            while(!st.empty() &&
                  temperatures[i] > temperatures[st.top()]) {

                int index = st.top();
                st.pop();

                ans[index] = i - index; //no of days to get warmer
            }
            
            st.push(i); // Push current days index
        }

        return ans;
    }
};